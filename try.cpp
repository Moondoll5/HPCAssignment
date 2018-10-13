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

int main(int argc, char *argv[]){
	std::stringstream test("this_is_a_test_string");
	std::string segment;
	std::vector<std::string> seglist;

	while(std::getline(test, segment, '_'))
	{
	   seglist.push_back(segment);
	}

	for (int i = 0; i < seglist.size(); ++i)
	{
		cout << seglist[i] <<endl;
	}

	return 0;
}