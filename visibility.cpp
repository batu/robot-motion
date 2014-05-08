#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

class Node{
public:
	double x;
	double y;
	vector <Node*> adjNode;
};

vector<double> buildGraph(vector<double> * start, vector<double> * end) {
	string line;
	vector<vector<double> > inputGraph;
	vector<string> file;
	int counter = 0;
	//Sample data section//
	ifstream inputFile ("sampleData.txt");
	if (inputFile.is_open()) {
		while (getline(inputFile, line)){
			cout << line << endl;
			file.push_back(line);
			counter++;
		}
		inputFile.close();
	}
	else{
		cout << "Unable to open file";
	}
	cout << file.size() << endl;
	//Convert string to vector
	string delimiter = " ";
	size_t pos = 0;
	string token;
	for (int i = 0; i < file.size(); i++){
		string thisLine = file[i];
		while((pos = thisLine.find(delimiter)) != std::string::npos){
			token = thisLine.substr(0, pos);
			cout << "reached here" << endl;
			cout << token << endl;
			cout << "reached here" << endl;
			cout << token << endl;
			cout << "reached here too" << endl;
			thisLine.erase(0, pos + delimiter.length());
		}
	}
}
//Do the sweep by looking at the angle.
//First take the information and create nodes from them
//Input type
int main() {
	vector<double> start, end;

	buildGraph(&start, &end);
}
