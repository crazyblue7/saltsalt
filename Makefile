CC = clang++
WINCC = wineg++

CODE = main.cpp
debug: $(CODE)
	$(CC) $(CODE) -o salty -g -lraylib
	./salty

rel: $(CODE)
	$(CC) $(CODE) -o salty -O0 -lraylib
	rm -rf bin
	mkdir bin -p
	mv salty bin/
win: $(CODE)
	$(WINCC) $(CODE) -o salty -O0 -lraylib
	rm -rf bin
	mkdir bin -p
	# since winegxx is kinda weird, make salty.exe the real exe
	rm salty.exe
	mv salty.exe.so bin/salty.exe
