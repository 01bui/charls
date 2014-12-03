/* 
 (C) Jan de Vaan 2007-2010, all rights reserved. See the accompanying "License.txt" for licensed use. 
*/ 


#ifndef CHARLS_CONFIG
#define CHARLS_CONFIG

#ifdef NDEBUG
#  ifndef ASSERT
#    define ASSERT(t) { }
#  endif
#else
#include <cassert>
#define ASSERT(t) assert(t)
#endif

#if defined(_WIN32)
#ifdef _MSC_VER
#pragma warning (disable:4512) // assignment operator could not be generated [VS2013]
#endif

#endif

/* Typedef used by Charls for the default integral type.  charls will work correctly with 64 or 32 bit. */
typedef long LONG;

enum constants
{
  LONG_BITCOUNT = sizeof(LONG)*8
};


#undef  NEAR

#ifndef inlinehint
#  ifdef _MSC_VER
#    ifdef NDEBUG
#      define inlinehint __forceinline
#    else
#      define inlinehint
#    endif
#  elif defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ > 0)
#    define inlinehint inline
#  else 
#    define inlinehint inline
#  endif
#endif

#if defined(i386) || defined(__i386__) || defined(_M_IX86) || defined(__amd64__) || defined(_M_X64)
#define ARCH_HAS_UNALIGNED_MEM_ACCESS /* TODO define this symbol for more architectures */
#endif

#endif
