#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <Eigen/Dense>
#include "Header.h"


using namespace std;

	int main() 
	{
		vector<int> x = { 0 };
		string filename = "data.txt";
		ifstream I(filename);
		vector<vector<int>> SLY;
		MyClass X;
		X.Input(I, SLY);
		static auto rows = SLY.size();
		static auto cols = SLY[0].size();
		for (auto i = 1; i < rows; ++i) x.push_back(0);
		X.Solve(SLY, x);



	}