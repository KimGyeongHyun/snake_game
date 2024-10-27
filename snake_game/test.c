#include "test.h"

int testInt;

void testFunction()
{
#if 0
	printf("hello world\n");
	scanf_s("%d", &testInt);
	printf("testInt: %d\n", testInt);
#endif
}