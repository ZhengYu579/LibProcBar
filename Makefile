all:ProcBar.c Main.c
	gcc -shared -fPIC -o libProcBar.so ProcBar.c -lpthread
	gcc Main.c -o test -lpthread -L./ -lProcBar

lib:ProcBar.c
	gcc -shared -fPIC -o libProcBar.so ProcBar.c -lpthread

test:Main.c
	gcc Main.c -o test -lpthread -l libProcBar.so

clean:
	rm -f libProcBar.so
	rm -f procbar

