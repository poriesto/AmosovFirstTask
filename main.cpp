#include "math.hpp"

int main(int argc, const char *argv[])
{
    std::vector<std::vector<int>> mat{
		{15,10,0,-6,17},
		{3,14,8,9,2},
		{1,5,14,20,-3},
		{7,19,10,2,0}
	};
	double param = 0.21;
  
	std::cout << "Init matrix" << std::endl;
	print(mat);
	MinMax(mat);
	Sav(mat);
	HW(mat, param);
	return 0;
}
