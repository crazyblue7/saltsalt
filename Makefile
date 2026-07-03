debug: main.cpp
	g++ main.cpp -o salty -g -lraylib
	./salty

rel: main.cpp
	g++ main.cpp -o salty -O0 -lraylib
