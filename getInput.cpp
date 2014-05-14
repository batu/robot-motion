/*
 * getInput.cpp
 *
 *  Created on: 13 May 2014
 *      Author: Asyrique
 */
#include<iostream>
#include<cmath>
#include<sstream>
#include<stdexcept>
#include<fstream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<cstdlib>

using namespace std;
////////////////////////////////////////////////////////////////////////////////
//Function to convert strings to doubles.
////////////////////////////////////////////////////////////////////////////////
class BadConversion : public std::runtime_error {
public:
  BadConversion(std::string const& s)
    : std::runtime_error(s)
    { }
};

inline double convertToDouble(std::string const& s)
{
  std::istringstream i(s);
  double x;
  if (!(i >> x))
    throw BadConversion("convertToDouble(\"" + s + "\")");
  return x;
}
////////////////////////////////////////////////////////////////////////////////

class Node{
public:
	double x;
	double y;
	vector <Node*> adjNode;
};

void buildGraph(Node * start, Node * end, vector<Node> * nodeList) {
	string line;
	vector<string> file;
	int counter = 0;
	//Sample data section//
	ifstream inputFile ("sampleData.txt");
	if (inputFile.is_open()) {
		while (getline(inputFile, line)){
			file.push_back(line);
			counter++;
		}
		inputFile.close();
	}
	else{
		cout << "Unable to open file";
	}

	//Convert string to vector
	vector<vector<double> > inputGraph;
	string delimiter = " ";
	size_t pos = 0;
	string token;
	for (int i = 0; i < file.size(); i++){
		string thisLine = file[i];
		inputGraph.push_back(vector <double>());
		while((pos = thisLine.find(delimiter)) != std::string::npos){
			token = thisLine.substr(0, pos);
			inputGraph[i].push_back(convertToDouble(token));
			thisLine.erase(0, pos + delimiter.length());
		}
		inputGraph[i].push_back(convertToDouble(thisLine));
	}

	///////Add values to start and end nodes/////
	start->x = inputGraph[0][0];
	start->y = inputGraph[0][1];
	inputGraph.erase(inputGraph.begin());
	end->x = inputGraph [0][0];
	end->y = inputGraph [0][1];
	inputGraph.erase(inputGraph.begin());

	////// Begin creating nodes ////
	for (int j = 0; j < inputGraph.size();j++){
		for (int k = 0; k < (inputGraph[j].size()-1); k+=2){
			Node *newNode;
			newNode = new Node;
			newNode->x = inputGraph[j][k];
			newNode->y = inputGraph[j][k+1];
			cout << "creating node x:" << newNode->x << " y:" << newNode->y << endl;
			nodeList->push_back(*newNode);
		}
	}
	//////Link adjacent nodes together/////
	/////Assuming that the nodes go into nodesList in order, just find the order,
	///find the number of nodes per object, and injects the adjacencies.
	int position = 0;
	for (int k = 0; k < inputGraph.size(); k++){
		int numOfElem = inputGraph[k].size() / 2;
		for (int l = 0; l < numOfElem; l++) {
			if (l == (numOfElem-1)){//If it's the last node
				(nodeList->at(position+l)).adjNode.push_back(&(nodeList->at(position+l-1)));//Add node before this one
				(nodeList->at(position+l)).adjNode.push_back(&(nodeList->at(position+0)));//Add first node in this part
			}
			else if (l == 0) {//If it's teh first node
				(nodeList->at(position+l)).adjNode.push_back(&(nodeList->at(position+(numOfElem - 1))));//Add last node in this part
				(nodeList->at(position+l)).adjNode.push_back(&(nodeList->at(position+l+1)));//Add second node
			}
			else{//Any other nodes
				(nodeList->at(position+l)).adjNode.push_back(&(nodeList->at(position+l+1)));//Add next node in list
				(nodeList->at(position+l)).adjNode.push_back(&(nodeList->at(position+l-1)));//Add previous node in list
			}
			cout << "Added adjacencies for Node: x." << nodeList->at(position + l).x << " y." << nodeList->at(position + l).y << endl;
		}
		position = position + numOfElem;//Add extra one because we want to avoid hitting the same element again on the first part of the subsequent loop.
	}
}

//Do the sweep by looking at the angle.
//First take the information and create nodes from them
//Input type

int main() {
	vector<Node> nodeList;
	Node start, end;

	buildGraph(&start, &end, &nodeList);
	cout << nodeList[0].x << endl;
	cout << nodeList[0].adjNode[0]->x <<endl;
	cout << nodeList[0].adjNode[0]->y << endl;
	cout << nodeList[0].adjNode[1]->x << endl;
	cout << nodeList[0].adjNode[1]->y << endl;
	cout << nodeList[2].x << endl;
}



