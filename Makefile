CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

all: bin/units

test: bin/test

bin/units: obj/main.o obj/lib.a
	g++ $(CFLAGS) -o $@ $^

obj/lib.a: obj/conversion.o obj/Check_Error.o obj/Print_Error.o
	ar rcs $@ $^

obj/main.o: src/units/main.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $< -o $@ -I src/lib

obj/conversion.o: src/lib/conversion.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $< -o $@

obj/Check_Error.o: src/lib/Check_Error.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $< -o $@

obj/Print_Error.o: src/lib/Print_Error.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean

bin/test: obj/test/main.o  obj/lib.a
	g++ $(CFLAGS) $(CPPFLAGS) -o $@ $^ -I src/lib

obj/test/main.o: test/main.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $< -o $@ -I thirdparty 

obj/test/test.o: test/parser_test.cpp
		g++ -c $(CFLAGS) $(CPPFLAGS) $< -o $@ -I thirdparty -I src/lib

clean:
	rm bin/units -f
	rm obj/*.o -f
	rm obj/*.d -f
	rm obj/test/*.d -f
	rm obj/test/*.o -f
	rm bin/test -f
