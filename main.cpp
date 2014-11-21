#include "math.hpp"
using namespace std;

int main(int argc, const char *argv[])
{
        vector<vector<int>> mat{
		{15,10,0,-6,17},
		{3,14,8,9,-2},
		{1,5,14,20,-3},
		{7,19,10,2,0}
	};
	vector<int>X{100,150,200,250,300};
	vector<double>P{0.1, 0.15, 0.25, 0.3, 0.2};
	double param = 0.21;
  
	cout << "Init matrix" << endl;
	print(mat);
	MinMax(mat);
	Sav(mat);
	HW(mat, param);
	BL(X, P);
	return 0;
}
