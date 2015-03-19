#include <stdlib.h>
#include <time.h>

void foo(int *x) {
    *x = *x / 2;
}

char* stackPtrEscape() {
    char const str[] = "string";
    return str; // stack address escaped
}


int main(int argc, char* argv[])
{

	// 1.1) Null Pointer Dereference
	int *p1;
	p1 = NULL;
	*p1 = 3;
	free(p1);

	// 1.2) Pointer Always Properly Allocated Before Dereference
	int *p2;
	p2 = NULL;
	if (1) {
		p2 = (int*)malloc(sizeof(int));
	}
	*p2 = 3;
	free(p2);

	// 1.3) Pointer Nondeterministically Allocated Before Dereference
	int *p3;
	p3 = NULL;
	if (time(NULL) % 2 == 0) {
		p3 = (int*)malloc(sizeof(int));
	}
	*p3 = 3;
	free(p3);
    
    // 2.1) Uninitialized Argument
    int *uninit = (int*) malloc(sizeof(int));
    foo(uninit);
    
    // 2.2) Argument Always Initialized
    int *initptr = (int*) malloc(sizeof(int));
    if (1) {
        *initptr = 4;
    }
    foo(initptr);
    
    // 2.3) Argument Nondeterministically Initialized
    int *npointer = (int*) malloc(sizeof(int));
    if (time(NULL) % 2 == 0) {
        *npointer = 4;
    }
    foo(npointer);
    
    // 3.1) Divide By Zero
    int a = 2;
    int zero = 0;
    a = a / zero;
    
    // 3.2) Never Divide By Zero
    int b = 2;
    int c = 0;
    if (1) {
        c++;
    }
    b = b / c;
    
    // 3.3) Nondeterministically Divide By Zero
    int d = 2;
    int e = 0;
    if (time(NULL) % 2 == 0) {
        e++;
    }
    d = d / e;
    
    // 4.1) Escaped Stack Pointer Dereferenced
    char *badPtr = stackPtrEscape();
    *badPtr;
    
    // 4.2) Escaped Stack Pointer Not Dereferenced
    stackPtrEscape();
    
    // 4.3) Escaped Stack Pointer Nondeterministically Dereferenced
    char *badPtr2 = stackPtrEscape();
    if (time(NULL) % 2 == 0) {
        *badPtr2;
    }
    
    // 5.1) Variable-Length Array Of Size Zero
    int f1 = 0;
    int badArr1[f1];
    
    // 5.2) Variable-Length Array Of Size Nonzero
    int f2 = 0;
    if (1) {
        f2 = 2;
    }
    int badArr2[f2];

    // 5.3) Variable-Length Array Of Nondeterministic Size
    int f3 = time(NULL) % 2;
    int badArr3[f3];
    
	return 0;
}

