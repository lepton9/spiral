

spiral:
	gcc -g -Wall spiral.cpp -lopengl32 -lglu32 -lfreeglut -o $@

run:
	./spiral
