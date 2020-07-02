CFLAGS 	= -Wall -Wextra -Wpedantic
LIBS 	= -lpthread


c:
	gcc $(CFLAGS) -std=c17 -O3 $(LIBS) -o code code.c
	gcc $(CFLAGS) -std=c17 -O3 $(LIBS) -o normal normal.c

cpp:
	g++ $(CFLAGS) -std=c++17 -O3 $(LIBS) -o code code.cpp
	g++ $(CFLAGS) -std=c++17 -O3 $(LIBS) -o normal normal.cpp

time:
	time ./code
	time ./normal

debugc:
	gcc $(CFLAGS) -std=c17 -g $(LIBS) -o code code.c && gdb ./code

debugcpp:
	g++ $(CFLAGS) -std=c++17 -g $(LIBS) -o code code.cpp && gdb ./code
