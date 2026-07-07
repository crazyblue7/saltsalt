CODE = main.cpp helper.cpp
debug: $(CODE)
	g++ $(CODE) -o salty -g -lraylib
	./salty

rel: $(CODE)
	g++ $(CODE) -o salty -O0 -lraylib
	rm -rf bin
	mkdir bin -p
	mv salty bin/
win: $(CODE)
	wineg++ $(CODE) -o salty -O0 -lraylib
	rm -rf bin
	mkdir bin -p
	# since winegcc is kinda weird, make salty.exe the real exe
	rm salty.exe
	mv salty.exe.so bin/salty.exe
