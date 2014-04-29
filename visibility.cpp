#include<iostream>
using namespace std;

class Node{
public:
	double x;
	double y;
	bool is_path;
};

class PEdge{
public:
// Conflict resolution, node1 small x node2 greater x, if x is the same check y.
	Node Node1;
	Node Node2;
};

class VEdge{
public:
// In the end all of the P edges should become VEdges..
	Node Node1;
	Node Node2;
	bool is_path;
};

//Do the sweep by looking at the angle.
int main() {




}
