#include <stdio.h>
#include "ospace.h"

OSPACE_DECLARE(SInt, char)
OSPACE_DEFINE(SInt, char)

int main() {
	SInt o;
	char buffer[32];
	printf("SInt_open(&o, buffer, 32).\n");
	SInt_open(&o, buffer, 32);
	printf("o.size: %d.\n", o.size);
	SInt_openHeap(&o, 64);
	printf("SInt_openHeap(&o, 64).\n");
	SInt_resize(&o, 128);
	printf("SInt_resize(&o, 128).\n");
	printf("o.size: %d.\n", o.size);
	SInt_close(&o);
	printf("SInt_close(&o).");
	return 0;
}
