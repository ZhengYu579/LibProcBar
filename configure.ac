#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(ProcBar, 1.0, user_zheng_yu@163.com)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([ProcBarLib/src/ProcBar.c])
AC_CONFIG_HEADERS([config.h])

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
