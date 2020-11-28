/*
This is a part of <dlibc> created for OS development

All code below can be incomplete and even dangerous for your applications
so take it to your mind before using it
*/

//"stdbool-dlibc.h" from stdbool.h
#ifndef _STDBOOL_H
#define _STDBOOL_H

#ifndef __cplusplus

#define bool	_Bool
#define true	1
#define false	0

#else /* __cplusplus */

/* Supporting _Bool in C++ is a GCC extension.  */
#define _Bool	bool

#if __cplusplus < 201103L
/* Defining these macros in C++98 is a GCC extension.  */
#define bool	bool
#define false	false
#define true	true
#endif

#endif /* __cplusplus */

/* Signal that all the definitions are present.  */
#define __bool_true_false_are_defined	1

#endif	/* stdbool.h */