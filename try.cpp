#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string.h> 
#include <cstdlib>
#include "dcdplugin.c"
#include <cmath>
#include <time.h>
#include <bits/stdc++.h>
#include <omp.h>
#include <stdlib.h>
#include <queue>
using namespace std;

// float bruteForce(Vector<int> points ){
// 	for (int i = 0; i < points.size(); ++i)
// 	{
// 		cout<< points.x << " " << points.y << " " << points.z << endl;
// 	}
// }

int main(int argc, char *argv[]){
	vector<int> points = {1,5,3,2,4,10,2};
	//std::priority_queue<int> q ={};
	float distance = pow(pow((points[0] - points[1]),2) + pow((points[3] - points[4]),2) + pow((points[5] - points[6]),2), 0.5);
	cout << distance << endl;



	// for (int i = 0; i < a.size(); ++i)
	// {
	// 	cout <<q.push(a[i]);
	// }

	
	return 0;
}

