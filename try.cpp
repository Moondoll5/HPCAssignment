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
using namespace std;

bool compare (int x, int y)
{
  if (x > y)
  {
  	return true;
  }else{
  	return false;
  }
}

int main(int argc, char *argv[]){
	vector<int> a = {1,5,3,2,4,10,2};

	cout << "SORT" << endl;

	for (int i = 0; i < 7; ++i)
	{
		cout << a[i] <<endl;
	}

	sort(a.begin(), a.end());
	
	cout << "after:" << endl;
	for (int i = 0; i < 7; ++i)
	{
		cout << a[i] <<endl;
	}




	return 0;
}

