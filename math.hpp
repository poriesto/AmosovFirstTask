#ifndef MATH_HPP
#define MATH_HPP
#include "api.hpp"

template<typename T> std::vector<T>getMinVector(std::vector<std::vector<T>>matrix)
{
  std::vector<T>min;
  for(auto value : matrix)
    {
      min.emplace_back(*min_element(value.begin(), value.end()));
    }
  return min;
}

template<typename T> std::vector<T> getMaxVector(std::vector<std::vector<T>> matrix)
{
  std::vector<T>max;
  for(auto value : matrix)
    {
      max.emplace_back(*max_element(value.begin(), value.end()));
    }
  return max;
}

template<typename T> void MinMax(std::vector<std::vector<T> > matrix)
{
  std::cout << "!======MinMax method======!" << std::endl;
  std::vector<T> min(getMinVector(matrix));
  std::cout << "Check min vector" << std::endl;
  print(min);
  //print max element from min vector
  std::cout << std::endl << "Result is " << *max_element(begin(min), end(min)) << std::endl;
}

template<typename T> void Sav(std::vector<std::vector<T> > matrix)
{
    std::vector<std::vector<T>>mat1(getRowColMatrix(matrix)), mat3;
    std::vector<T>mat2;
    T max = 0;

    std::cout << std::endl << "!======Savage method======!" << std::endl;
    for(auto& value : mat1) {
        max = *max_element(value.begin(), value.end());
        for (auto& tmp : value)
        {
            tmp = max - tmp;
        }
    }
    std::cout << "\nCheck mat1 \n";
    print(mat1);
    //return col to col, row to row
    for(unsigned int i = 0; i < matrix.size(); i++)
      {
	mat3.push_back(getCol(mat1, i));
	}
    std::cout << "Check mat3: " << std::endl;
    print(mat3);
    mat2 = getMaxVector(mat3);
    std::cout << "Mat2 check: " << std::endl;
    print(mat2);
    std::cout << std::endl << "Result of Savage method: " << *min_element(mat2.begin(), mat2.end()) << std::endl;

}
template<typename T> void HW(std::vector<std::vector<T> > matrix, double C)
  {
    std::vector<T> min, max;
    std::vector<double> result;
    double tmp = 0;
    std::vector<std::vector<T>> mat1;

    std::cout << std::endl << "!======HW method======!" << std::endl;
    if(C <= 1 && C >= 0)
    {
        min = getMinVector(matrix);
        max = getMaxVector(matrix);
        std::cout << "Check min:" << std::endl;
        print(min);
        std::cout << std::endl << "Check max:" << std::endl;
        print(max);
        for(auto iterMin = min.begin(), iterMax = max.begin();
                 iterMin != min.end(), iterMax != max.end();
                 iterMin++, iterMax++)
        {
	  tmp = C * (*iterMin) + ( 1 - C) * (*iterMax);
	  result.push_back( tmp );
        }
        std::cout << std::endl << "Check result" << std::endl;
        print(result);
        std::cout << std::endl << "Result of HW method: " << *max_element(result.begin(), result.end()) << std::endl;
    }
    else
    {
        std::cout << std::endl << "C value not valid" << std::endl;
	std::cout << "Please check this parameter" << std::endl;
    }
}

template<typename T> bool checkP(std::vector<T> matrix)
{
  double sum = 0;
  bool result;
  for(auto value : matrix) sum += value;
  
  if(sum < 1 || sum == 1) result = true;
  else result = false;
  
  return result;
}

template<typename T> void BL(std::vector<T>X, std::vector<double>P)
{
  std::cout << std::endl << "!======BL method======!";
  if(checkP(P))
    {
      std::cout << ": " << std::endl << "P(x) is valud" << std::endl;
    }
  else
    {
      std::cout << "is failed. Please check P(x)" << std::endl;
    }
}

#endif
