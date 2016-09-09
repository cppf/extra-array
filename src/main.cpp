#include <stdio.h>
#include "coll/olist.h"


OARRAY_DECLARE(AInt, int)
OARRAY_DEFINE(AInt, int)


int main() {
	AInt o;
	char buffer[32];

	AInt_open(&o, buffer, 32 / sizeof(int));
	printf("AInt_open(&o, buffer, 32 / sizeof(int)).\n");
	printf("o.space: %d.\n", o.space);
	o.at[o.space - 1] = 0x0BADB055;
	printf("o.at[o.space - 1]: %x.\n", o.at[o.space - 1]);

	AInt_openHeap(&o, 64);
	printf("AInt_openHeap(&o, 64).\n");
	printf("o.space: %d.\n", o.space);
	o.at[o.space - 1] = 0x600DB055;
	printf("o.at[o.space - 1]: %x.\n", o.at[o.space - 1]);

	AInt_close(&o);
	printf("AInt_close(&o).\n");

	AInt_openHeap(&o, 128);
	printf("AInt_openHeap(&o, 128).\n");
	AInt_reopen(&o, 256);
	printf("AInt_reopen(&o, 256).\n");
	printf("o.space: %d.\n", o.space);
	AInt_close(&o);
	printf("AInt_close(&o).\n");
	return 0;
}
