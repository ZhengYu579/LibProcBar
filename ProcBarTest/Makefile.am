#子目录Makefile.am
#目标是要生成可执行文件，并且引用动态库或静态库

#目标执行文件名
bin_PROGRAMS=testprocbar

#当前目录路径
CUR_PATH = $(top_srcdir)/ProcBarTest

#源码文件
testprocbar_SOURCES = src/main.c

#头文件
testprocbar_CPPFLAGS = -I$(top_srcdir)/ProcBarLib/inc

#关联库路径静态库
#STATIC_LIB_PATH = $(CUR_PATH)/lib
#静态库
#testprocbar_LDADD = $(STATIC_LIB_PATH)/libhrxmodule.a

#关联库路径动态库
SHARE_LIB_PATH = -L$(PWD)/../ProcBarLib/.libs
SHARE_LIBS  = -lprocbar -lpthread
#动态库
testprocbar_LDADD = $(SHARE_LIB_PATH) $(SHARE_LIBS) 

#编译选项
AM_LDFLAGS = 

