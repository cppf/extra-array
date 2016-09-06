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
	inline size_t N##_resize(void* o, size_t size)

#define OARRAY_FB_RESIZE(N, T) \
	OARRAY_FD_RESIZE(N, T) { \
		N* z = (N*)o; \
		z->at = (T*)realloc(z->at, size * sizeof(T)); \
		z->size = size; \
		return size; \
	}


// Get size.
// args: array.
#define OARRAY_FD_SIZE(N, T) \
	inline size_t N##_size(void* o)

#define OARRAY_FB_SIZE(N, T) \
	OARRAY_FD_SIZE(N, T) { \
		N* z = (N*)o; \
		return z->size; \
	}


// Get begin index, forward.
// args: array.
#define OARRAY_FD_BEGIN(N, T) \
	inline size_t N##_begin(void* o)

#define OARRAY_FB_BEGIN(N, T) \
	OARRAY_FD_BEGIN(N, T) { \
		return 0; \
	}


// Get end index, forward.
// args: array.
#define OARRAY_FD_END(N, T) \
	inline size_t N##_end(void* o)

#define OARRAY_FB_END(N, T) \
	OARRAY_FD_END(N, T) { \
		return N##_size(o); \
	}


// Get begin index, backward.
// args: array.
#define OARRAY_FD_BEGINBACK(N, T) \
	inline size_t N##_beginBack(void* o)

#define OARRAY_FB_BEGINBACK(N, T) \
	OARRAY_FD_BEGINBACK(N, T) { \
		return N##_size(o) - 1; \
	}


// Get end index, backward.
// args: array.
#define OARRAY_FD_ENDBACK(N, T) \
	inline size_t N##_endBack(void* o)

#define OARRAY_FB_ENDBACK(N, T) \
	OARRAY_FD_ENDBACK(N, T) { \
		return -1; \
	}


// Get whether next value exists.
// args: array, index.
#define OARRAY_FD_HASNEXT(N, T) \
	inline int N##_hasNext(void* o, size_t i)

#define OARRAY_FB_HASNEXT(N, T) \
	OARRAY_FD_HASNEXT(N, T) { \
		return i != N##_end(); \
	}


// Get whether previous value exists.
// args: array, index.
#define OARRAY_FD_HASPREV(N, T) \
	inline size_t N##_hasPrev(void* o, size_t i)

#define OARRAY_FB_HASPREV(N, T) \
	OARRAY_FD_HASPREV(N, T) { \
		return i != N##_endBack(); \
	}


// Get index of next value.
// args: array, index.
#define OARRAY_FD_NEXT(N, T) \
	inline size_t N##_next(void* o, size_t i)

#define OARRAY_FB_NEXT(N, T) \
	OARRAY_FD_NEXT(N, T) { \
		return i + 1; \
	}


// Get index of previous value.
// args: array, index.
#define OARRAY_FD_PREV(N, T) \
	inline size_t N##_prev(void* o, size_t i)

#define OARRAY_FB_PREV(N, T) \
	OARRAY_FD_PREV(N, T) { \
		return i - 1; \
	}


// Get value at index.
// args: array, index.
#define OARRAY_FD_GET(N, T) \
	inline T N##_get(void* o, size_t i)

#define OARRAY_FB_GET(N, T) \
	OARRAY_FD_GET(N, T) { \
		N* z = (N*)o; \
		return z->at[i]; \
	}


// Set value at index.
// args: array, index, value.
#define OARRAY_FD_SET(N, T) \
	inline T N##_set(void* o, size_t i, T v)

#define OARRAY_FB_SET(N, T) \
	OARRAY_FD_SET(N, T) { \
		N* z = (N*)o; \
		return (z->at[i] = v); \
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
	OARRAY_FD_RESIZE(N, T); \
	OARRAY_FD_SIZE(N, T); \
	OARRAY_FD_BEGIN(N, T); \
	OARRAY_FD_END(N, T); \
	OARRAY_FD_BEGINBACK(N, T); \
	OARRAY_FD_ENDBACK(N, T); \
	OARRAY_FD_HASNEXT(N, T); \
	OARRAY_FD_HASPREV(N, T); \
	OARRAY_FD_NEXT(N, T); \
	OARRAY_FD_PREV(N, T); \
	OARRAY_FD_GET(N, T); \
	OARRAY_FD_SET(N, T);


// Define array type.
// This defines functions.
// args: name, type.
#define OARRAY_DEFINE(N, T) \
	OARRAY_FB_OPEN(N, T) \
	OARRAY_FB_OPENHEAP(N, T) \
	OARRAY_FB_CLOSE(N, T) \
	OARRAY_FB_RESIZE(N, T) \
	OARRAY_FB_SIZE(N, T) \
	OARRAY_FB_BEGIN(N, T) \
	OARRAY_FB_END(N, T) \
	OARRAY_FB_BEGINBACK(N, T) \
	OARRAY_FB_ENDBACK(N, T) \
	OARRAY_FB_HASNEXT(N, T) \
	OARRAY_FB_HASPREV(N, T) \
	OARRAY_FB_NEXT(N, T) \
	OARRAY_FB_PREV(N, T) \
	OARRAY_FB_GET(N, T) \
	OARRAY_FB_SET(N, T)
#pragma endregion


#endif // !_OARRAY_H_
