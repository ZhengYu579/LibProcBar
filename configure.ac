#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT

LIBPROCBAR_MAJOR_VERSION=1
LIBPROCBAR_MINOR_VERSION=0
LIBPROCBAR_MICRO_VERSION=3
LIBPROCBAR_VERSION=$LIBPROCBAR_MAJOR_VERSION.$LIBPROCBAR_MINOR_VERSION.$LIBPROCBAR_MICRO_VERSION$LIBPROCBAR_MICRO_VERSION_SUFFIX
LIBPROCBAR_VERSION_INFO=`expr $LIBPROCBAR_MAJOR_VERSION + $LIBPROCBAR_MINOR_VERSION`:$LIBPROCBAR_MICRO_VERSION:$LIBPROCBAR_MINOR_VERSION

VERSION=${LIBPROCBAR_VERSION}

AM_INIT_AUTOMAKE(libprocbar, $VERSION)
AC_CONFIG_SRCDIR([ProcBarLib/inc])
AC_CONFIG_HEADERS([config.h])

# -version-info
AC_SUBST(LIBPROCBAR_VERSION)
AC_SUBST(LIBPROCBAR_VERSION_INFO)

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.
AC_CHECK_LIB(z -lpthread, deflate, [], [])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h sys/ioctl.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile
                 ProcBarLib/Makefile
                 ProcBarTest/Makefile])
AC_OUTPUT
