#ifndef _ESTACK_H_
#define _ESTACK_H_


#pragma region required headers
#include <stddef.h>
#include "earray.h"
#pragma endregion



#pragma region type
// Structure for stack.
// args: name, type.
#define ESTACK_TS(N, T) \
	typedef struct _##N { \
		T* at; \
		size_t space; \
		size_t size; \
	} N
#pragma endregion



#pragma region function
// Open with static memory.
// args: stack, at, space.
#define ESTACK_FB_OPEN(N, T) { \
		N* z = (N*)o; \
		T* _at = N##_oarray_open(o, at, space); \
		z->size = 0; \
		return _at; \
	}


// Open with heap memory.
// args: stack, space.
#define ESTACK_FB_OPENHEAP(N, T) { \
		N* z = (N*)o; \
		T* at = N##_oarray_openHeap(o, size); \
		z->size = 0; \
		return at; \
	}


// Reopen with different space (heap only).
// args: stack, space.
#define ESTACK_FB_REOPEN(N, T) { \
		N* z = (N*)o; \
		T* at = N##_oarray_reopen(o, space); \
		if(space < z->size) z->size = space; \
		return at; \
	}


// Get size.
// args: stack.
#define ESTACK_FB_SIZE(N, T) { \
		N* z = (N*)o; \
		return z->size; \
	}


// Get top offset of stack.
// args: stack.
#define ESTACK_FD_TOP(N, T) \
	inline size_t N##_top(void* o)

#define ESTACK_FB_TOP(N, T) { \
		return N##_size() - 1; \
	}


// Push value to end.
#define ELIST_FS_PUSH(N, T) \
	inline T N##_push(void* o, T v)

#define ELIST_FB_PUSH(N, T) { \
		


#define ELIST_FD_POP(N, T) \
	inline T N##_pop(void* o)

#define ELIST_FD_PUSHAT(N, T) \
	inline T N##_pushAt(void* o, size_t i, T v)

#define ELIST_FD_POPAT(N, T) \
	inline T N##_popAt(void* o, size_t i)

#define ELIST_FD_REMOVE(N, T) \


#pragma endregion



#pragma region macro
// Declare list types.
// args: name, type.
#define ELIST_DECLARE_TS(N, T) \
	EARRAY_DECLARE_TS(N##_oarray, T) \
	ELIST_TS(N, T);


// Declare list functions.
// args: name, type.
#define ELIST_DECLARE_FS(N, T) \
	EARRAY_DECLARE_FS(N##_oarray, T) \
	EARRAY_DECLARE_FS(N, T) \
	ELIST_FS_ROOM(N, T);


// Declare list types and functions.
// args: name, type.
#define ELIST_DECLARE(N, T) \
	ELIST_DECLARE_TS(N, T) \
	ELIST_DECLARE_FS(N, T)


// Define list types and functions.
// args: name, type.
#define ELIST_DEFINE(N, T) \
	EARRAY_DEFINE(N##_oarray, T) \
	EARRAY_FS_OPEN(N, T) \
	ELIST_FB_OPEN(N, T) \
	EARRAY_FS_OPENHEAP(N, T) \
	ELIST_FB_OPENHEAP(N, T) \
	EARRAY_FS_RESIZE(N, T) \
	ELIST_FB_RESIZE(N, T) \
	EARRAY_FS_SIZE(N, T) \
	ELIST_FB_SIZE(N, T) \
	ELIST_FS_ROOM(N, T) \
	EARRAY_FB_SIZE(N, T) \
	EARRAY_FS_CLOSE(N, T) \
	EARRAY_FB_CLOSE(N, T) \
	EARRAY_FS_BEGIN(N, T) \
	EARRAY_FB_BEGIN(N, T) \
	EARRAY_FS_END(N, T) \
	EARRAY_FB_END(N, T) \
	EARRAY_FS_BEGINBACK(N, T) \
	EARRAY_FB_BEGINBACK(N, T) \
	EARRAY_FS_ENDBACK(N, T) \
	EARRAY_FB_ENDBACK(N, T) \
	EARRAY_FS_HASNEXT(N, T) \
	EARRAY_FB_HASNEXT(N, T) \
	EARRAY_FS_HASPREV(N, T) \
	EARRAY_FB_HASPREV(N, T) \
	EARRAY_FS_NEXT(N, T) \
	EARRAY_FB_NEXT(N, T) \
	EARRAY_FS_PREV(N, T) \
	EARRAY_FB_PREV(N, T) \
	EARRAY_FS_GET(N, T) \
	EARRAY_FB_GET(N, T) \
	EARRAY_FS_SET(N, T) \
	EARRAY_FB_SET(N, T)
#pragma endregion


#endif // !_ELIST_H_
