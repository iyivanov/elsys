// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
// ELSYS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// This header contains common definitions for the ELSYS programmes.
// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#include <stdio.h>
#include <strings.h>

#ifndef _ELSYS_H_
#define _ELSYS_H_


#ifndef PRINT_NEW_LINE
#define PRINT_NEW_LINE printf("\n")
#endif


#ifndef _ELSYS_BOOL
#define _ELSYS_BOOL

// define names for 0 and 1 as boolean true and false
typedef enum bool_t
{
    false, true
} bool;

#endif

#endif