#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[])
{
	// 1. Null Pointer Dereference
	int *p1;
	p1 = NULL;
	*p1 = 3;
	free(p1);

	// 2. Null Pointer Always Properly Allocated Before Dereference
	int *p2;
	p2 = NULL;
	if (1) {
		p2 = (int*)malloc(sizeof(int));
	}
	*p2 = 3;
	free(p2);

	// 3. Null Pointer Sometimes Allocated Before Dereference
	int *p3;
	p3 = NULL;
	if (time(NULL) % 2 == 0) {
		p3 = (int*)malloc(sizeof(int));
	}
	*p3 = 3;
	free(p3);

	return 0;
}

