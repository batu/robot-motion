#include<iostream>
#include<cmath>
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


bool compareAngleBigger(	double xbase, double ybase,
							double x1,    double y1,
							double x2,    double y2)
{
	double relx1, relx2, rely1, rely2;
	int quadrant1, quadrant2;
	relx1 = x1 - xbase;
	relx2 = x2 - xbase;
	rely1 = y1 - ybase;
	rely2 = y2 - ybase;

		 if(relx1 > 0 and rely1 > 0) {quadrant1 = 1;}
	else if(relx1 < 0 and rely1 > 0) {quadrant1 = 2;}
	else if(relx1 < 0 and rely1 < 0) {quadrant1 = 3;}
	else if(relx1 > 0 and rely1 < 0) {quadrant1 = 4;}

		 if(relx2 > 0 and rely2 > 0) {quadrant2 = 1;}
	else if(relx2 < 0 and rely2 > 0) {quadrant2 = 2;}
	else if(relx2 < 0 and rely2 < 0) {quadrant2 = 3;}
	else if(relx2 > 0 and rely2 < 0) {quadrant2 = 4;}

	if ( quadrant1 > quadrant2)	{ return true  ;}
	if ( quadrant2 > quadrant1)	{ return false ;}
	if (quadrant1 == quadrant2){
			 if ((relx1 / rely1) > (relx2 / rely2))  { return true  ;}
		else if ((relx1 / rely1) < (relx2 / rely2))  { return false ;}

	}
}

bool compareDistanceBigger( double xbase, double ybase,
					  double x1, 	double y1,
					  double x2, 	double y2)
{

	double distance1, distance2;

	distance1 = sqrt(pow((xbase - x1),2) + pow((ybase - y1),2));
	distance2 = sqrt(pow((xbase - x2),2) + pow((ybase - y2),2));

	if (distance1 > distance2) {
		return true;
	} else {
		return false;
	}

}

int main() {

long x1 = 0, y1 = 0, x2 = 1, y2 = 4, x3 = 10, y3 = 4;

cout << compareDistanceBigger(x1,y1,x2,y2,x3,y3);
}


