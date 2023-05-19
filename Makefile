CFLAGS = -Wall -Wextra -Werror

all: bin/units

bin/units: obj/conversion.o obj/main.o
	g++ -o $(CFLAGS) -o $@ $^

obj/main.o: src/units/main.cpp
	$(CC) -c $(CFLAGS) $< -o $@ -I src/lib

obj/conversion.o: src/lib/conversion.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm bin/units
	rm obj/*.o