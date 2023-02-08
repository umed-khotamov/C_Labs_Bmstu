#ifndef __ERRS_DEFS_H__
#define __ERRS_DEFS_H__

#define MAX_ARGS 4
#define MIN_ARGS 3

#define FILE_IN 1
#define FILE_OUT 2

#define FILTER "f"

#define SORT 1
#define FILTER_SORT 2

#define EMPTY 0

enum errors
{
	ERR_ARGS = 100,
	ERR_FILE_OPEN,
	ERR_MALLOC,
	ERR_WRONG_POINTERS,
	ERR_EMPTY_ARRAY,
	ERR_READ_FILE,
	ERR_EMPTY_FILE
};

#endif
