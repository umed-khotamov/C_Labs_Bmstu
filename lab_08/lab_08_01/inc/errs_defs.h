#ifndef __ERRS_DEFS_H__

#define __ERRS_DEFS_H__

#define EPS 1e-7

#define EMPTY 0
#define EQUAL 0

#define DELROWS 1
#define DELCOLS 2

enum errors
{
    ERSINPUT = 100,
    ERPINPUT,
    ERMALLOC,
    ERELINPUT,
};

#endif
