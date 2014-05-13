/*
 * buildVGraph.cpp
 *
 *  Created on: 13 May 2014
 *      Author: Asyrique
 */
#include<iostream>

using namespace std;

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



