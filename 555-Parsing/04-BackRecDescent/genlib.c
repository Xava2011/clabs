/*
 * File: genlib.c
 * Version: 1.0-WB
 * Last modified on Sun Jul 24 10:29:46 1994 by eroberts
 * Last modified on Fri Dec 24 12:00:00 1999 by wbzyl
 *   removed references to `gcalloc'
 * -----------------------------------------------------
 * This file implements the general C library package.  See the
 * interface description in genlib.h for details.
 */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>

#include "genlib.h"
#include "exception.h"

/*
 * Constants:
 * ----------
 * ErrorExitStatus -- Status value used in exit call
 * MaxErrorMessage -- Longest error message allowed
 */

#define ErrorExitStatus 1
#define MaxErrorMessage 500

/* Section 1 -- Define new "primitive" types */

/*
 * Constant: UNDEFINED
 * -------------------
 * This entry defines the target of the UNDEFINED constant.
 */

char undefined_object[] = "UNDEFINED";

/* Section 2 -- Memory allocation */

/* Memory allocation implementation */

void *GetBlock(size_t nbytes)
{
    void *result;
    result = malloc(nbytes);
    if (result == NULL) Error("No memory available");
    return (result);
}

void FreeBlock(void *ptr)
{
  free(ptr);
}

/* Section 3 -- Basic error handling */

/*
 * Implementation notes: Error
 * ---------------------------
 * Writing the Error function requires some care, since it is
 * called in circumstances in which parts of the system may be
 * broken.  In particular, it is not acceptable for Error to
 * call GetBlock, since the error condition may be that the
 * system is out of memory, in which case calling GetBlock would
 * fail.  The error string should be allocated dynamically,
 * so that this function can be used in reentrant code.
 * Note that it is critical to exit if the length bound for
 * an error message is exceeded, since this error almost
 * certainly corrupts the stack.
 */

void Error(string msg, ...)
{
    va_list args;
    char errbuf[MaxErrorMessage + 1];
    string errmsg;
    int errlen;

    va_start(args, msg);
    vsprintf(errbuf, msg, args);
    va_end(args);
    errlen = strlen(errbuf);
    if (errlen > MaxErrorMessage) {
        fprintf(stderr, "Error: Error Message too long\n");
        exit(ErrorExitStatus);
    }
    errmsg = malloc(errlen + 1);
    if (errmsg == NULL) {
        errmsg = "No memory available";
    } else {
        strcpy(errmsg, errbuf);
    }
    if (HandlerExists(&ErrorException)) {
        RaiseException(&ErrorException, "ErrorException", errmsg);
    } else {
        fprintf(stderr, "Error: %s\n", errmsg);
        exit(ErrorExitStatus);
    }
}
