#ifndef STATUSTYPE_H
#define STATUSTYPE_H

typedef enum {
	SUCCESS = 0,
	FAILURE = -1,
	ALLOCATION_ERROR = -2,
	INVALID_INPUT = -3
} StatusType;

#endif