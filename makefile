all:visibilityGraph


visibilityGraph: getInput.o buildVGraph.o findPath.o
	g++ getInput.o buildVGraph.o findPath.o -o visibilityGraph.exe


getInput: getInput.o
	g++ -std=c++11 getInput.o -o getInput.exe

getInput.o: getInput.cpp
	g++ -c getInput.cpp

buildVGraph: buildVGraph.o
	g++ -std=c++11 buildVGraph.o -o buildVGraph.exe

buildVGraph.o:buildVGraph.cpp
	g++ -c buildVGraph.cpp

visibility: visibility.o
	g++ -std=c++11 visibility.o -o visibility.exe

visibility.o:visibility.cpp
	g++ -std=c++11 -c visibility.cpp

rungetInput: getInput.exe
	./getInput.exe

runbuildVGraph: buildVGraph.exe
	./buildVGraph.exe

runVisibility: visibility.exe
	./visibility.exe

runAll: visibilityGraph
	cmd visibilityGraph.exe

clean:
	rm -rf *o *exe