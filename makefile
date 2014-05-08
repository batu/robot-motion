all:visibilityGraph


visibilityGraph: avl.o classes.o visibility.o
	g++ avl.o classes.o visibility.o -o visibilityGraph.exe


avl: avl.o
	g++ -std=c++11 avl.o -o avl.exe

avl.o: avl.cpp
	g++ -c avl.cpp

classes: classes.o
	g++ -std=c++11 classes.o -o classes.exe

classes.o:classes.cpp
	g++ -c classes.cpp

visibility: visibility.o
	g++ -std=c++11 visibility.o -o visibility.exe

visibility.o:visibility.cpp
	g++ -std=c++11 -c visibility.cpp

runAvl: avl.exe
	./avl.exe

runClasses: classes.exe
	cmd classes.exe

runVisibility: visibility.exe
	cmd visibility.exe

runAll: visibilityGraph
	cmd visibilityGraph.exe

clean:
	rm -rf *o *exe