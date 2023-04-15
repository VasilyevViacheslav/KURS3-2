
#include <iostream>
#include <Eigen/Dense>
#include <vector>
using namespace Eigen;
using namespace std;
class MyClass
{
public:
	template<typename T = int>
	void Input(ifstream& file, vector<vector<T>>& SLY)
	{
		if (!file.is_open()) return;
		vector<T> buff;
		T value;
		string line;
		while (getline(file, line)) { 
			stringstream ss(line); 
			while (ss >> value) { 
				buff.push_back(value);
			}
			SLY.push_back(buff); 
			buff.clear();
		}
	};
	
	template<typename T>
	void Solve(vector<vector<T>> F, vector<T> S) {
		MatrixXf A(F.size() + 1, F[0].size());
		MatrixXf b(F.size() + 1, 1);
		for (auto i = 0; i < F.size(); ++i) {
			for (auto j = 0; j < F[i].size(); ++j) {
				A(i, j) = F[i][j];
			}
		}
		for (auto i = 0; i < F[0].size(); ++i) {
			A(F.size(), i) = 1;
		}
		b.setZero();
		b(F.size(), 0) = 1;
		VectorXf x = A.colPivHouseholderQr().solve(b);

		if (x.minCoeff() >= 0 && x.sum() == 1) {
			std::cout << "The point is inside the tetrahedron" << std::endl;
		}
		else {
			std::cout << "The point is outside the tetrahedron" << std::endl;
		}
	}

};
