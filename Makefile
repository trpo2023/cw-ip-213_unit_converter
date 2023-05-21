CFLAGS = -Wall -Wextra -Werror

all: bin/units

test: bin/test

bin/units: obj/main.o obj/conversion.o obj/Check_Error.o obj/Print_Error.o
	g++ $(CFLAGS) -o $@ $^

obj/main.o: src/units/main.cpp
	g++ -c $(CFLAGS) $< -o $@ -I src/lib

obj/conversion.o: src/lib/conversion.cpp
	g++ -c $(CFLAGS) $< -o $@

obj/Check_Error.o: src/lib/Check_Error.cpp
	g++ -c $(CFLAGS) $< -o $@

obj/Print_Error.o: src/lib/Print_Error.cpp
	g++ -c $(CFLAGS) $< -o $@

.PHONY: clean

bin/test: obj/test/main.o  obj/test/test.o obj/conversion.o obj/Check_Error.o
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
