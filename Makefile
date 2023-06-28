spiral:
	gcc -g -Wall spiral.cpp -I"./include/GL/" -L"./lib/x64/" -lfreeglut -lopengl32 -lglu32 -o $@

spiralOld:
	gcc -g -Wall spiral.cpp -lopengl32 -lglu32 -lfreeglut -o $@

run:
	./spiral
