# ospace

Generic memory region (space) in C.


## structure

```c
at : T*
size : size_t
```


## usage

### declare

```c
// Declare a space type.
// This defines structure and declares functions.
OSPACE_DECLARE(name, type)
```

```c
// declare int space
OSPACE_DECLARE(SInt, int)
```


## define

```c
// Define a space type.
// This define functions.
OSPACE_DEFINE(name, type)
```

```c
// define int space
OSPACE_DEFINE(SInt, int)
```


### open

```c
// Open with static memory.
#_open(space, at, size)

```

```c
// define space and char buffer
SInt o;
char buffer[32];

// open with buffer
SInt_open(&o, buffer, 32/sizeof(int));

// print size of space
printf("%d", o.size);

// write 0x0BADB055 at last index
o.at[o.size-1] = 0x0BADB055;
```


## openHeap

```c
// Open with heap memory.
#_openHeap(space, size)
```

```c
// open of size 64
SInt_openHeap(&o, 64);

// print size of space
printf("%d", o.size);

// write 0x600DB055 at last index
o.at[o.size-1] = 0x600DB055;
```


### close

```c
// Close, if opened with heap memory.
#_close(space)
```

```c
// close space
SInt_close();
```


### resize

```c
// Resize if opened with heap memory.
#_resize(space, size)
```

```c
// open of size 128
SInt_openHeap(&o, 128);

// resize to size 256
SInt_resize(&o, 256);
```
