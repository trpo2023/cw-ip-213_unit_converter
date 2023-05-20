CFLAGS = -Wall -Wextra -Werror

all: bin/units

test: bin/test

bin/units: obj/main.o obj/conversion.o
	g++ $(CFLAGS) -o $@ $^

obj/main.o: src/units/main.cpp
	g++ -c $(CFLAGS) $< -o $@ -I src/lib

obj/conversion.o: src/lib/conversion.cpp
	g++ -c $(CFLAGS) $< -o $@

.PHONY: clean

bin/test: obj/test/main.o  obj/test/test.o obj/conversion.o
	g++ $(CFLAGS) -o $@ $^ -I src/lib

obj/test/main.o: test/main.cpp
	g++ -c $(CFLAGS) $< -o $@ -I thirdparty 

obj/test/test.o: test/parser_test.cpp
		g++ -c $(CFLAGS) $< -o $@ -I thirdparty -I src/lib

clean:
	rm bin/units -f
	rm obj/*.o -f
	rm obj/test/*.o -f
	rm bin/test -f