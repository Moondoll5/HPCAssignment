#include <omp.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
	cout << argv[0] << endl;//File path
	cout << argv[1] << endl;//-i
	cout <<argv[2] << endl;//inputfile

	//Name of the input file given as argument
	string filename = argv[2];

	//Reading a file
	ifstream infile;
	infile.open(filename);

	//Initialise variables
	string input[4]={};
	int count = 0;
	string line;

	//Read file into array
	while(getline(infile, line)) {
        input[count] = line;
        count++;
    }

    //Create A and B subsets
    

	//Close the file
	infile.close();

	return 0;
}