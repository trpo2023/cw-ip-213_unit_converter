CFLAGS = -Wall -Wextra -Werror

all: bin/units

bin/units: obj/main.o obj/conversion.o
	g++ -o $(CFLAGS) -o $@ $^

obj/main.o: src/units/main.cpp
	g++ -c $(CFLAGS) $< -o $@ -I src/lib

obj/conversion.o: src/lib/conversion.cpp
	g++ -c $(CFLAGS) $< -o $@

clean:
	rm bin/units
	rm obj/*.o