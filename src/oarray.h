#ifndef _OARRAY_H_
#define _OARRAY_H_


// Dhrtarastra said: O Sanjaya, what did my sons desirous of battle and the sons of Pandu do
// after assembling at the holy land of righteousness, Kuruksetra?
// ref: http://www.bhagavad-gita.org/Gita/verse-01-01.html


#pragma region required headers
#include <stddef.h>
#include <stdlib.h>
#pragma endregion



#pragma region type
// Define structure for array.
// args: name, type.
#define OARRAY_TYPE(N, T) \
	typedef struct _##N { \
		T* at; \
		size_t size; \
	} N
#pragma endregion



#pragma region function
// Open with static memory.
// args: array, at, size.
#define OARRAY_FD_OPEN(N, T) \
	inline T* N##_open(void* o, void* at, size_t size)

#define OARRAY_FB_OPEN(N, T) \
	OARRAY_FD_OPEN(N, T) { \
		N* z = (N*)o; \
		z->at = (T*)at; \
		z->size = size; \
		return z->at; \
	}


// Open with heap memory.
// args: array, size.
#define OARRAY_FD_OPENHEAP(N, T) \
	inline T* N##_openHeap(void* o, size_t size)

#define OARRAY_FB_OPENHEAP(N, T) \
	OARRAY_FD_OPENHEAP(N, T) { \
		N* z = (N*)o; \
		z->at = (T*)malloc(size * sizeof(T)); \
		z->size = size; \
		return z->at; \
	}


// Close, if opened with heap memory.
// args: array.
#define OARRAY_FD_CLOSE(N, T) \
	inline T* N##_close(void* o)

#define OARRAY_FB_CLOSE(N, T) \
	OARRAY_FD_CLOSE(N, T) { \
		N* z = (N*)o; \
		free(z->at); \
		return NULL; \
	}


// Resize, if opened with heap memory.
// args: array, size.
#define OARRAY_FD_RESIZE(N, T) \
	inline T* N##_resize(void* o, size_t size)

#define OARRAY_FB_RESIZE(N, T) \
	OARRAY_FD_RESIZE(N, T) { \
		N* z = (N*)o; \
		z->at = (T*)realloc(z->at, size * sizeof(T)); \
		z->size = size; \
		return z->at; \
	}
#pragma endregion



#pragma region macro
// Declare array type.
// This defines structure and declares functions.
// args: name, type.
#define OARRAY_DECLARE(N, T) \
	OARRAY_TYPE(N, T); \
	OARRAY_FD_OPEN(N, T); \
	OARRAY_FD_OPENHEAP(N, T); \
	OARRAY_FD_CLOSE(N, T); \
	OARRAY_FD_RESIZE(N, T);


// Define array type.
// This defines functions.
// args: name, type.
#define OARRAY_DEFINE(N, T) \
	OARRAY_FB_OPEN(N, T) \
	OARRAY_FB_OPENHEAP(N, T) \
	OARRAY_FB_CLOSE(N, T) \
	OARRAY_FB_RESIZE(N, T)
#pragma endregion


#endif // !_OARRAY_H_
