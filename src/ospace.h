#ifndef _OSPACE_H_
#define _OSPACE_H_


// Dhrtarastra said: O Sanjaya, what did my sons desirous of battle and the sons of Pandu do
// after assembling at the holy land of righteousness, Kuruksetra?
// ref: http://www.bhagavad-gita.org/Gita/verse-01-01.html


#pragma region required headers
#include <stddef.h>
#include <stdlib.h>
#pragma endregion



#pragma region type
// Define structure for space.
// args: name, type.
#define OSPACE_TYPE(N, T) \
	typedef struct _##N { \
		T* at; \
		size_t size; \
	}N
#pragma endregion



#pragma region function
// Open with static memory.
// args: space, at, size.
#define OSPACE_FD_OPEN(N, T) \
	inline T* N##_open(void* o, void* at, size_t size)

#define OSPACE_FB_OPEN(N, T) \
	OSPACE_FD_OPEN(N, T) { \
		N* z = (N*)o; \
		z->at = (T*)at; \
		z->size = size; \
		return z->at; \
	}


// Open with heap memory.
// args: space, size.
#define OSPACE_FD_OPENHEAP(N, T) \
	inline T* N##_openHeap(void* o, size_t size)

#define OSPACE_FB_OPENHEAP(N, T) \
	OSPACE_FD_OPENHEAP(N, T) { \
		N* z = (N*)o; \
		z->at = (T*)malloc(size * sizeof(T)); \
		z->size = z->at? size : 0; \
		return z->at; \
	}


// Close, if opened with heap memory.
// args: space.
#define OSPACE_FD_CLOSE(N, T) \
	inline T* N##_close(void* o)

#define OSPACE_FB_CLOSE(N, T) \
	OSPACE_FD_CLOSE(N, T) { \
		N* z = (N*)o; \
		free(z->at); \
		return NULL; \
	}


// Resize if opened with heap memory.
// args: space, size.
#define OSPACE_FD_RESIZE(N, T) \
	inline T* N##_resize(void* o, size_t size)

#define OSPACE_FB_RESIZE(N, T) \
	OSPACE_FD_RESIZE(N, T) { \
		N* z = (N*)o; \
		z->at = (T*)realloc(z->at, size * sizeof(T)); \
		z->size = z->at ? size : 0; \
		return z->at; \
	}
#pragma endregion



#pragma region macro
// Declare a space type.
// This defines structure and declares functions.
// args: name, type.
#define OSPACE_DECLARE(N, T) \
	OSPACE_TYPE(N, T); \
	OSPACE_FD_OPEN(N, T); \
	OSPACE_FD_OPENHEAP(N, T); \
	OSPACE_FD_CLOSE(N, T); \
	OSPACE_FD_RESIZE(N, T);


// Define a space type.
// This define functions.
// args: name, type.
#define OSPACE_DEFINE(N, T) \
	OSPACE_FB_OPEN(N, T) \
	OSPACE_FB_OPENHEAP(N, T) \
	OSPACE_FB_CLOSE(N, T) \
	OSPACE_FB_RESIZE(N, T)
#pragma endregion


#endif // !_OSPACE_H_
