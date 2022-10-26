all:./src/ProcBar.c ./src/Main.c
	rm -rf ./lib
	rm -rf ./testApp
	mkdir lib
	mkdir testApp
	gcc -shared -fPIC -o ./lib/libProcBar.so ./src/ProcBar.c -lpthread -I./inc
	gcc ./src/Main.c -o ./testApp/test -lpthread -L./lib -lProcBar -I./inc

procbar:./src/ProcBar.c
	mkdir lib
	gcc -shared -fPIC -o ./lib/libProcBar.so ./src/ProcBar.c -lpthread -I./inc

test:./src/Main.c
	mkdir testApp
	gcc ./src/Main.c -o ./testApp/test -lpthread -L./lib -lProcBar -I./inc

clean:
	rm -rf ./lib
	rm -rf ./testApp
