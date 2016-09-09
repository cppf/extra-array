#ifndef _OSTACK_H_
#define _OSTACK_H_


#pragma region required headers
#include <stddef.h>
#include "oarray.h"
#pragma endregion



#pragma region type
// Structure for stack.
// args: name, type.
#define OSTACK_TS(N, T) \
	typedef struct _##N { \
		T* at; \
		size_t space; \
		size_t size; \
	} N
#pragma endregion



#pragma region function
// Open with static memory.
// args: stack, at, space.
#define OSTACK_FB_OPEN(N, T) { \
		N* z = (N*)o; \
		T* _at = N##_oarray_open(o, at, space); \
		z->size = 0; \
		return _at; \
	}


// Open with heap memory.
// args: stack, space.
#define OSTACK_FB_OPENHEAP(N, T) { \
		N* z = (N*)o; \
		T* at = N##_oarray_openHeap(o, size); \
		z->size = 0; \
		return at; \
	}


// Reopen with different space (heap only).
// args: stack, space.
#define OSTACK_FB_REOPEN(N, T) { \
		N* z = (N*)o; \
		T* at = N##_oarray_reopen(o, space); \
		if(space < z->size) z->size = space; \
		return at; \
	}


// Get size.
// args: stack.
#define OSTACK_FB_SIZE(N, T) { \
		N* z = (N*)o; \
		return z->size; \
	}


// Get top offset of stack.
// args: stack.
#define OSTACK_FD_TOP(N, T) \
	inline size_t N##_top(void* o)

#define OSTACK_FB_TOP(N, T) { \
		return N##_size() - 1; \
	}


// Push value to end.
#define OLIST_FS_PUSH(N, T) \
	inline T N##_push(void* o, T v)

#define OLIST_FB_PUSH(N, T) { \
		


#define OLIST_FD_POP(N, T) \
	inline T N##_pop(void* o)

#define OLIST_FD_PUSHAT(N, T) \
	inline T N##_pushAt(void* o, size_t i, T v)

#define OLIST_FD_POPAT(N, T) \
	inline T N##_popAt(void* o, size_t i)

#define OLIST_FD_REMOVE(N, T) \


#pragma endregion



#pragma region macro
// Declare list types.
// args: name, type.
#define OLIST_DECLARE_TS(N, T) \
	OARRAY_DECLARE_TS(N##_oarray, T) \
	OLIST_TS(N, T);


// Declare list functions.
// args: name, type.
#define OLIST_DECLARE_FS(N, T) \
	OARRAY_DECLARE_FS(N##_oarray, T) \
	OARRAY_DECLARE_FS(N, T) \
	OLIST_FS_ROOM(N, T);


// Declare list types and functions.
// args: name, type.
#define OLIST_DECLARE(N, T) \
	OLIST_DECLARE_TS(N, T) \
	OLIST_DECLARE_FS(N, T)


// Define list types and functions.
// args: name, type.
#define OLIST_DEFINE(N, T) \
	OARRAY_DEFINE(N##_oarray, T) \
	OARRAY_FS_OPEN(N, T) \
	OLIST_FB_OPEN(N, T) \
	OARRAY_FS_OPENHEAP(N, T) \
	OLIST_FB_OPENHEAP(N, T) \
	OARRAY_FS_RESIZE(N, T) \
	OLIST_FB_RESIZE(N, T) \
	OARRAY_FS_SIZE(N, T) \
	OLIST_FB_SIZE(N, T) \
	OLIST_FS_ROOM(N, T) \
	OARRAY_FB_SIZE(N, T) \
	OARRAY_FS_CLOSE(N, T) \
	OARRAY_FB_CLOSE(N, T) \
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
	OARRAY_FB_SET(N, T)
#pragma endregion


#endif // !_OLIST_H_
