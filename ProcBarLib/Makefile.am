#子目录Makefile.am

#软件等级 foreign、gnu、gnits
AUTOMAKE_OPTIONS = foreign

#表示要生成动态库
lib_LTLIBRARIES = libprocbar.la

# 添加库的版本信息
libprocbar_la_LDFLAGS =\
	-version-info @LIBPROCBAR_VERSION_INFO@

#当前目录路径
CUR_PATH = $(top_srcdir)/ProcBarLib

#链接头文件
AM_CFLAGS = -I$(CUR_PATH)/inc

#头文件, make install 时会安装到目标目录
include_HEADERS = $(CUR_PATH)/inc/ProcBar.h

#源码文件
libprocbar_la_SOURCES = src/ProcBar.c
