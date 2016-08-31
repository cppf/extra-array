#include <stdio.h>
#include "ospace.h"


OSPACE_DECLARE(SInt, int)
OSPACE_DEFINE(SInt, int)


int main() {
	SInt o;
	char buffer[32];

	SInt_open(&o, buffer, 32 / sizeof(int));
	printf("SInt_open(&o, buffer, 32 / sizeof(int)).\n");
	printf("o.size: %d.\n", o.size);
	o.at[o.size - 1] = 0x0BADB055;
	printf("o.at[o.size - 1]: %x.\n", o.at[o.size - 1]);

	SInt_openHeap(&o, 64);
	printf("SInt_openHeap(&o, 64).\n");
	printf("o.size: %d.\n", o.size);
	o.at[o.size - 1] = 0x600DB055;
	printf("o.at[o.size - 1]: %x.\n", o.at[o.size - 1]);

	SInt_close(&o);
	printf("SInt_close(&o).\n");

	SInt_openHeap(&o, 128);
	printf("SInt_openHeap(&o, 128).\n");
	SInt_resize(&o, 256);
	printf("SInt_resize(&o, 256).\n");
	printf("o.size: %d.\n", o.size);
	SInt_close(&o);
	printf("SInt_close(&o).\n");
	return 0;
}
