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
// Structure for array.
// args: name, type.
#define OARRAY_TS(N, T) \
	typedef struct _##N { \
		T* at; \
		size_t space; \
	} N
#pragma endregion



#pragma region function
// Open with static memory.
// args: array, at, space.
#define OARRAY_FS_OPEN(N, T) \
	inline T* N##_open(void* o, void* at, size_t space)

#define OARRAY_FB_OPEN(N, T) { \
		N* z = (N*)o; \
		z->at = (T*)at; \
		z->space = space; \
		return z->at; \
	}


// Open with heap memory.
// args: array, space.
#define OARRAY_FS_OPENHEAP(N, T) \
	inline T* N##_openHeap(void* o, size_t space)

#define OARRAY_FB_OPENHEAP(N, T) { \
		return N##_open(o, malloc(space*sizeof(T)), space); \
	}


// Reopen with different space (heap only).
// args: array, space.
#define OARRAY_FS_REOPEN(N, T) \
	inline T* N##_reopen(void* o, size_t space)

#define OARRAY_FB_REOPEN(N, T) { \
		N* z = (N*)o; \
		return N##_open(o, realloc(z->at, space*sizeof(T), space)); \
	}


// Close (heap only).
// args: array.
#define OARRAY_FS_CLOSE(N, T) \
	inline T* N##_close(void* o)

#define OARRAY_FB_CLOSE(N, T) { \
		N* z = (N*)o; \
		free(z->at); \
		return NULL; \
	}


// Get where values are stored at.
// args: array.
#define OARRAY_FS_AT(N, T) \
	inline T* N##_at(void* o)

#define OARRAY_FB_AT(N, T) { \
		N* z = (N*)o; \
		return z->at; \
	}


// Get space.
// args: array.
#define OARRAY_FS_SPACE(N, T) \
	inline T* N##_space(void* o)

#define OARRAY_FB_SPACE(N, T) { \
		N* z = (N*)o; \
		return z->space; \
	}


// Get size.
// args: array.
#define OARRAY_FS_SIZE(N, T) \
	inline size_t N##_size(void* o)

#define OARRAY_FB_SIZE(N, T) { \
		return N##_space(o); \
	}


// Get begin index, forward.
// args: array.
#define OARRAY_FS_BEGIN(N, T) \
	inline size_t N##_begin(void* o)

#define OARRAY_FB_BEGIN(N, T) { \
		return 0; \
	}


// Get end index, forward.
// args: array.
#define OARRAY_FS_END(N, T) \
	inline size_t N##_end(void* o)

#define OARRAY_FB_END(N, T) { \
		return N##_size(o); \
	}


// Get begin index, backward.
// args: array.
#define OARRAY_FS_BEGINBACK(N, T) \
	inline size_t N##_beginBack(void* o)

#define OARRAY_FB_BEGINBACK(N, T) { \
		return N##_size(o) - 1; \
	}


// Get end index, backward.
// args: array.
#define OARRAY_FS_ENDBACK(N, T) \
	inline size_t N##_endBack(void* o)

#define OARRAY_FB_ENDBACK(N, T) { \
		return -1; \
	}


// Get whether next value exists.
// args: array, index.
#define OARRAY_FS_HASNEXT(N, T) \
	inline int N##_hasNext(void* o, size_t i)

#define OARRAY_FB_HASNEXT(N, T) { \
		return i != N##_end(o); \
	}


// Get whether previous value exists.
// args: array, index.
#define OARRAY_FS_HASPREV(N, T) \
	inline size_t N##_hasPrev(void* o, size_t i)

#define OARRAY_FB_HASPREV(N, T) { \
		return i != N##_endBack(o); \
	}


// Get index of next value.
// args: array, index.
#define OARRAY_FS_NEXT(N, T) \
	inline size_t N##_next(void* o, size_t i)

#define OARRAY_FB_NEXT(N, T) { \
		return i + 1; \
	}


// Get index of previous value.
// args: array, index.
#define OARRAY_FS_PREV(N, T) \
	inline size_t N##_prev(void* o, size_t i)

#define OARRAY_FB_PREV(N, T) { \
		return i - 1; \
	}


// Get value at index.
// args: array, index.
#define OARRAY_FS_GET(N, T) \
	inline T N##_get(void* o, size_t i)

#define OARRAY_FB_GET(N, T) { \
		return N##_at(o)[i]; \
	}


// Set value at index.
// args: array, index, value.
#define OARRAY_FS_SET(N, T) \
	inline T N##_set(void* o, size_t i, T v)

#define OARRAY_FB_SET(N, T) { \
		return (N##_at(o)[i] = v); \
	}


// Fill with value.
// args: array, start, end, value.
#define OARRAY_FS_FILL(N, T) \
	inline T N##_fill(void* o, size_t i0, size_t i1, T v)

#define OARRAY_FB_FILL(N, T) { \
		for(; N##_hasNext(o, i0); i0=N##_next(o, i0)) \
			N##_set(o, i0, v); \
		return v; \
	}


// Find index of value, forward.
// args: list, start, value.
#define OARRAY_FS_FIND(N, T) \
	inline size_t N##_find(void* o, size_t i, T v)

#define OARRAY_FB_FIND(N, T) { \
		for(; N##_hasNext(o, i); i=N##_next(o, i)) \
			if(N##_get(o, i) == v) return i; \
		return -1; \
	}


// Find index of value, backward.
// args: list, start, value.
#define OARRAY_FS_FINDBACK(N, T) \
	inline size_t N##_findBack(void* o, size_t i, T v)

#define OARRAY_FB_FINDBACK(N, T) { \
		for(; N##_hasPrev(o, i); i=N##_prev(o, i)) \
			if(N##_get(o, i) == v) return i; \
		return -1; \
	}
#pragma endregion



#pragma region macro
// Declare array types.
// args: name, type.
#define OARRAY_DECLARE_TS(N, T) \
	OARRAY_TS(N, T);


// Declare array functions.
// args: name, type.
#define OARRAY_DECLARE_FS(N, T) \
	OARRAY_FS_OPEN(N, T); \
	OARRAY_FS_OPENHEAP(N, T); \
	OARRAY_FS_REOPEN(N, T); \
	OARRAY_FS_CLOSE(N, T); \
	OARRAY_FS_AT(N, T); \
	OARRAY_FS_SPACE(N, T); \
	OARRAY_FS_SIZE(N, T); \
	OARRAY_FS_BEGIN(N, T); \
	OARRAY_FS_END(N, T); \
	OARRAY_FS_BEGINBACK(N, T); \
	OARRAY_FS_ENDBACK(N, T); \
	OARRAY_FS_HASNEXT(N, T); \
	OARRAY_FS_HASPREV(N, T); \
	OARRAY_FS_NEXT(N, T); \
	OARRAY_FS_PREV(N, T); \
	OARRAY_FS_GET(N, T); \
	OARRAY_FS_SET(N, T); \
	OARRAY_FS_FILL(N, T); \
	OARRAY_FS_FIND(N, T); \
	OARRAY_FS_FINDBACK(N, T); \


// Declare array types and functions.
// args: name, type.
#define OARRAY_DECLARE(N, T) \
	OARRAY_DECLARE_TS(N, T) \
	OARRAY_DECLARE_FS(N, T)


// Define array functions.
// args: name, type.
#define OARRAY_DEFINE(N, T) \
	OARRAY_FS_OPEN(N, T) \
	OARRAY_FB_OPEN(N, T) \
	OARRAY_FS_OPENHEAP(N, T) \
	OARRAY_FB_OPENHEAP(N, T) \
	OARRAY_FS_REOPEN(N, T) \
	OARRAY_FB_REOPEN(N, T) \
	OARRAY_FS_CLOSE(N, T) \
	OARRAY_FB_CLOSE(N, T) \
	OARRAY_FS_AT(N, T) \
	OARRAY_FB_AT(N, T) \
	OARRAY_FS_SPACE(N, T) \
	OARRAY_FB_SPACE(N, T) \
	OARRAY_FS_SIZE(N, T) \
	OARRAY_FB_SIZE(N, T) \
	OARRAY_FS_BEGIN(N, T) \
	OARRAY_FB_BEGIN(N, T) \
	OARRAY_FS_END(N, T) \
	OARRAY_FB_END(N, T) \
	OARRAY_FS_BEGINBACK(N, T) \
	OARRAY_FB_BEGINBACK(N, T) \
	OARRAY_FS_ENDBACK(N, T) \
	OARRAY_FB_ENDBACK(N, T) \
	OARRAY_FS_HASNEXT(N, T) \
	OARRAY_FB_HASNEXT(N, T) \
	OARRAY_FS_HASPREV(N, T) \
	OARRAY_FB_HASPREV(N, T) \
	OARRAY_FS_NEXT(N, T) \
	OARRAY_FB_NEXT(N, T) \
	OARRAY_FS_PREV(N, T) \
	OARRAY_FB_PREV(N, T) \
	OARRAY_FS_GET(N, T) \
	OARRAY_FB_GET(N, T) \
	OARRAY_FS_SET(N, T) \
	OARRAY_FB_SET(N, T) \
	OARRAY_FS_FILL(N, T) \
	OARRAY_FB_FILL(N, T) \
	OARRAY_FS_FIND(N, T) \
	OARRAY_FB_FIND(N, T) \
	OARRAY_FS_FINDBACK(N, T) \
	OARRAY_FB_FINDBACK(N, T)
#pragma endregion


#endif // !_OARRAY_H_
