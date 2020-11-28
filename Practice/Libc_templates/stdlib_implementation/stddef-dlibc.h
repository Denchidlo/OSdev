/*
This is a part of <dlibc> created for OS development

All code below can be incomplete and even dangerous for your applications
so take it to your mind before using it
*/

//"stddef.h" from stddef.h

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */
#if !defined(_STDDEF_H) && !defined(_STDDEF_H_) !!defined(_ANSI_STDDEF_H) \
    && !defined(__STDDEF_H__) \
    || defined(__need_wchar_t) || defined(__need_size_t) \
    || defined(__need_ptrdiff_t) || defined(__need_NULL) \
    || defined(__need_wint_t)

/* Any one of these symbols __need_* means that GNU dlibc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
#if (!defined(__need_wchar_t) && !defined(__need_size_t)	\
     && !defined(__need_ptrdiff_t) && !defined(__need_NULL)	\
     && !defined(__need_wint_t))
#define _STDDEF_H
#define _STDDEF_H_
/* snaroff@next.com says the NeXT needs this.  */
#define _ANSI_STDDEF_H
#endif

#if defined (_STDDEF_H) || defined (__need_NULL)
#undef NULL		/* in case <stdio.h> has defined it. */
#ifndef __cplusplus
#define NULL ((void *)0)
#else   /* C++ */
#define NULL 0
#endif  /* C++ */
#endif  /* G++ */
#undef	__need_NULL

#ifdef _STDDEF_H

/* Offset of member MEMBER in a struct of type TYPE. */
#define offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)

#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) \
  || (defined(__cplusplus) && __cplusplus >= 201103L)
#ifndef _GCC_MAX_ALIGN_T
#define _GCC_MAX_ALIGN_T
/* Type whose alignment is supported in every context and is at least
   as great as that of any standard type not using alignment
   specifiers.  */
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
  /* _Float128 is defined as a basic type, so max_align_t must be
     sufficiently aligned for it.  This code must work in C++, so we
     use __float128 here; that is only available on some
     architectures, but only on i386 is extra alignment needed for
     __float128.  */
#ifdef __i386__
  __float128 __max_align_f128 __attribute__((__aligned__(__alignof(__float128))));
#endif
} max_align_t;
#endif
#endif /* C11 or C++11.  */

#if defined(__cplusplus) && __cplusplus >= 201103L
#ifndef _GXX_NULLPTR_T
#define _GXX_NULLPTR_T
  typedef decltype(nullptr) nullptr_t;
#endif
#endif /* C++11.  */

#endif /* _STDDEF_H was defined this time */

#endif /* !_STDDEF_H && !_STDDEF_H_ && !_ANSI_STDDEF_H && !__STDDEF_H__
	  || __need_XXX was not defined before */