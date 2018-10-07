#include <omp.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

	//Reading a file
	ifstream infile;
	cout << "Enter filename:" << endl;
	string filename;
	cin >> filename;
	infile.open(filename);
	string data;
	infile >> data;

	//Write data to screen
	cout << data << endl;

	//Close the file
	infile.close();

	return 0;
}