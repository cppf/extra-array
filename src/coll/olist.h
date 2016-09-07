#ifndef _OLIST_H_
#define _OLIST_H_


#pragma region required headers
#include <stddef.h>
#include "oarray.h"
#pragma endregion



#pragma region type
// Structure for list.
// args: name, type.
#define OLIST_TS(N, T) \
	typedef struct _##N { \
		T* at; \
		size_t room; \
		size_t size; \
	} N
#pragma endregion



#pragma region function
// Open with static memory.
// args: list, at, size.
#define OLIST_FB_OPEN(N, T) { \
		N* z = (N*)o; \
		z->size = 0; \
		return N##_oarray_open(o, at, size); \
	}


// Open with heap memory.
// args: list, size.
#define OLIST_FB_OPENHEAP(N, T) { \
		N* z = (N*)o; \
		z->size = 0; \
		return N##_oarray_openHeap(o, size); \
	}


// Resize, if opened with heap memory.
// args: list, size.
#define OLIST_FB_RESIZE(N, T) { \
		N* z = (N*)o; \
		if(size < z->size) z->size = size; \
		return N##_oarray_resize(o, size); \
	}


// Get room.
// args: list.
#define OLIST_FS_ROOM(N, T) \
	inline size_t N##_room(void* o)


// Get size.
// args: list.
#define OLIST_FB_SIZE(N, T) { \
		N* z = (N*)o; \
		return z->size; \
	}
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
