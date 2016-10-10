CFLAGS=\
	-std=c++11\
	-Wall\
	-Werror


LIBFILES=\
	triangle.cpp


all: x11 test llvm


test: *.cpp *.h
	g++ $(CFLAGS) $(LIBFILES) test.cpp -o test
	./test


llvm: *.cpp *.h
	clang++ $(CFLAGS) $(LIBFILES) test.cpp -o test


x11: *.cpp *.h
	g++ $(CFLAGS) $(LIBFILES) x11.cpp -L/usr/lib/x86_64-linux-gnu/ -lX11 -o x11
	clang++ $(CFLAGS) $(LIBFILES) x11.cpp -L/usr/lib/x86_64-linux-gnu/ -lX11 -o x11


clean:
	rm -f a.out *.o *.gch *.orig x11 test
