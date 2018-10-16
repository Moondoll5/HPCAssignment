#include <omp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <string.h> 
#include <cstdlib>
#include "dcdplugin.c"
#include <cmath>
#include <math.h>
#include <time.h>
#include <bits/stdc++.h>
#include <omp.h>


using namespace std;

priority_queue<float> distances;

struct point{
	float x;
	float y;
	float z;
	bool set; //True is A and False is B
};

vector<string> splitByComma(string set){
	//Separates text input into individual indices and stores into an array.

	std::stringstream points(set);
	std::string segment;
	std::vector<std::string> seglist;

	while(std::getline(points, segment,','))
	{
	   seglist.push_back(segment);
	}
	return seglist;
}

vector<int> dashRemover(vector<string> set){
	vector<int> indices;
	for (int i = 0; i < set.size(); ++i)
	{
		if (set[i].find('-') != std::string::npos)
		{
			//Needs to get all indices indicated by dash
			std::stringstream points(set[i]);
			std::string segment;
			int count = 0;
			int start = 0;
			int end = 0;

			while(std::getline(points, segment,'-'))
			{
				if (count == 0)
				{
					//First value saved as start
					start = atoi(segment.c_str());
				}else{
					//Second value saved as end
					end = atoi(segment.c_str());
				}

				if (end != 0)
				{
					//Adds all ints from start to end to indices list.
					for (int i = start; i < end+1; ++i)
					{
						indices.push_back(i);
					}
				}			  
			    count++;
			}
		}else{
			//If it has no dash, the index value is just added to the list
			indices.push_back(atoi(set[i].c_str()));
		}
	}

	return indices;
}

bool compareX(const point& a, const point& b)
{
	//Compares X values of points to sort vector.
  return a.x < b.x;
}

float bruteForce(vector<point> points ){
	float min = FLT_MAX;
	vector<float> mins;
	float distance;
	int index = 0;
	for (int i = 0; i < points.size(); i++)
	{
		//cout<< points[i].x << " " << points[i].y << " " << points[i].z << endl;
		for (int j = 1; j < points.size(); j++)
		{
			if ((points[i].set && !points[j].set) || (!points[i].set && points[j].set))
			{
				distance = sqrt(std::pow(((points[i].x) - (points[j].x)),2) + std::pow(((points[i].y) - (points[j].y)),2) + std::pow(((points[i].z) - (points[j].z)),2));
				if (distance < min)
				{
					min = distance;
					mins.push_back(distance);
					index = i;
				}
			}
		}
	}
	sort(mins.begin(), mins.end());
	cout<<"mins:"<<endl;
	for (int i = 0; i < mins.size(); ++i)
	{
		cout << mins[i] << endl;
	}
	// cout << "min: " << min;
	// cout << "index: " << index;

	return 0;
}



int main(int argc, char *argv[]){
	//Name of the input file given as argument
	string filename = argv[2];

	//Reading a file
	ifstream infile;
	infile.open(filename);

	if(infile.is_open()){
		//Initialise variables
		string input[4]={};
		int count = 0;
		string line;

		//Read file into array
		while(getline(infile, line)) {
	        input[count] = line;

	        count++;
	    }

	    //Arguments
	    string dcdFilename, k, subsetA, subsetB;
		dcdFilename = input[0];
		k = input[1];
		subsetA = input[2];
		subsetB = input[3];

		//Prints text file values
		cout << dcdFilename<<endl;
		cout << k << endl;
		cout << subsetA << endl;
		cout << subsetB << endl;
		infile.close();
		
		//Removes comma between indices
		vector<string> a, b;
		vector<int>  setA, setB;
		a = splitByComma(subsetA);
		b = splitByComma(subsetB);

		//Removes dashes and adds each index individually
		setA = dashRemover(a);
		setB = dashRemover(b);


		int natoms;
		dcdhandle *dcd; molfile_timestep_t timestep;
		void *v = open_dcd_read(dcdFilename.c_str(), "dcd", &natoms);
		dcd = (dcdhandle *)v;
		cout << "natoms: " << natoms << endl;

		timestep.coords = (float *)malloc(3*sizeof(float)*natoms);
		vector<point> points;
		for (int i=0; i<dcd->nsets; i++) {
            int rc = read_next_timestep(v, natoms, &timestep);
            cout<< "Timestep: " << i << endl;

  			for(int j = 0; j < setA.size(); j++){
  				float xA, yA, zA;
  				int posA = setA[j];
  				xA = *(timestep.coords+(3*posA));
  				yA  = *(timestep.coords+(3*posA) + 1);
  				zA = *(timestep.coords+(3*posA)+2);
  				// if (posA == 313)
  				// {
  				// 	cout<<"X:"<<xA<<endl;
  				// 	cout<<"Y:"<<yA<<endl;
  				// 	cout<<"Z:"<<zA<<endl;
  				// }
  				point cd = {xA, yA, zA, true};
  				points.push_back(cd);

  			}

  			for (int k = 0; k < setB.size(); k++){
  				float xB, yB, zB;
  					int posB = setB[k];
  					xB = *(timestep.coords+(3*posB));
	  				yB  = *(timestep.coords+(3*posB) + 1);
	  				zB = *(timestep.coords+(3*posB)+2);
	  			// 	if (posB == 168052)
  				// {
  				// 	cout<<"X:"<<xB<<endl;
  				// 	cout<<"Y:"<<yB<<endl;
  				// 	cout<<"Z:"<<zB<<endl;
  				// }
	  				point cd = {xB, yB, zB, false};
	  				points.push_back(cd);
  			}

	  		//Sorts by x value
			sort(points.begin(), points.end(), compareX);

			//Get middle point
			int mid = points.size()/2;

			float num = points[mid].x;

			bruteForce(points);
		}

		
		


	} else {
		std::cout << "Error: File cannot be opened";
	}

	return 0;
}