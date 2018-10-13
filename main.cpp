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

using namespace std;

vector<int> unroll(string line){

	vector<int> result;

	// convert line such as 5-15 to a vector such as [5,6,7,8,9,10,11,12,13,14,15]

	return result;
}

int main(int argc, char *argv[]) {
	const auto arg = std::string{ "-i" };
	std::string filename = "test"; // you should look for the filename from argv

	std::ifstream inputfile;
	inputfile.open(filename);

	if(inputfile.is_open()){
		string dcdFilename, kValue, subsetA, subsetB;
		dcdFilename = "../../textfile.dcd";
		kValue = 3;
		subsetA = "1-403";
		subsetB = "168043-168052";

		cout << dcdFilename << endl;
		cout << kValue << endl;
		cout << subsetA << endl;
		cout << subsetB << endl;
		inputfile.close();
		
		vector<int> setA, setB;
		setA = unroll(subsetA); // unroll should convert 1-403 to 1, 2, 3, 4, 5, 6, ...., 403
		setB = unroll(subsetB);

		int natoms;
		dcdhandle *dcd; molfile_timestep_t timestep;
		void *v = open_dcd_read(dcdFilename.c_str(), "dcd", &natoms);
		dcd = (dcdhandle *)v;
		cout << "natoms: " << natoms << endl;

		timestep.coords = (float *)malloc(3*sizeof(float)*natoms);
		for (int i=0; i<dcd->nsets; i++) {
            int rc = read_next_timestep(v, natoms, &timestep);

  			for(int j = 0; j < setA.size(); j++){
  				float x1, x2, y1, y2, z1, z2;
  				int val = setA[j];
  				x1 = *(timestep.coords+(3*val));
  				y1  = *(timestep.coords+(3*val) + 1);
  				z1 = *(timestep.coords+(3*val)+2);

  				for (int k = 0; k < setB.size(); k++){
  					int valTwo = setB[k];
  					x2 = *(timestep.coords+(3*valTwo));
	  				y2  = *(timestep.coords+(3*valTwo) + 1);
	  				z2 = *(timestep.coords+(3*valTwo)+2);

  				}
  			}
		}
	} else {
		std::cout << "Error: File cannot be opened!";
	}

	return 1;
}

