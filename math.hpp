#ifndef MATH_HPP
#define MATH_HPP
#include "api.hpp"

template<typename T> void MinMax(std::vector<std::vector<T> > matrix)
{
  std::cout << "MinMax method" << std::endl;
  std::vector<T> min;

  //create min vector
  for(auto value : matrix)
    {
      min.push_back(*min_element(value.begin(), value.end()));
    }
  std::cout << "Check min vector" << std::endl;
  print(min);
  std::cout << std::endl << "Result is " << *max_element(begin(min), end(min)) << std::endl;
}

template<typename T> void Sav(std::vector<std::vector<T> > matrix)
{
  std::vector<std::vector<T>>mat1, mat3;
    std::vector<T>mat2;
    T max = 0;
    std::cout << std::endl << "Savage method" << std::endl;
    for(unsigned int i = 0; i <= matrix.size(); i++)
    {
        mat1.push_back(getCol(matrix,i));
    }
    for(auto& value : mat1) {
        max = *max_element(value.begin(), value.end());
        for (auto& tmp : value)
        {
            tmp = max - tmp;
        }
    }
    std::cout << "\nCheck mat1 \n";
    print(mat1);
    for(unsigned int i = 0; i < matrix.size(); i++)
      {
	mat3.push_back(getCol(mat1, i));
      }
    std::cout << "Check mat3:" << std::endl;
    print(mat3);
    for(auto value : mat3)
    {
        mat2.push_back(*max_element(value.begin(), value.end()));
    }
    std::cout << "Mat2 check: " << std::endl;
    print(mat2);
    std::cout << std::endl << "Result of Savage method: " << *min_element(mat2.begin(), mat2.end());

}
template<typename T> void HW(std::vector<std::vector<T> > matrix, double C)
  {
    std::vector<T> min, max, result;
    std::vector<std::vector<T>> mat1;
    std::cout << std::endl << "HW method" << std::endl;
    if(C <= 1 && C >= 0)
    {
        for(unsigned int i = 0; i < matrix.size(); i++)
        {
            mat1.push_back(getCol(matrix, i));
        }
        std::cout << "Check mat1" << std::endl;
        print(mat1);
        for(auto value : mat1)
        {
            max.push_back(*max_element(value.begin(), value.end()));
            min.push_back(*min_element(value.begin(), value.end()));
        }
        std::cout << std::endl << "Check min:" << std::endl;
        print(min);
        std::cout << std::endl << "Check max:" << std::endl;
        print(max);
        for(auto iterMin = min.begin(), iterMax = max.begin();
                 iterMin != min.end(), iterMax != max.end();
                 iterMin++, iterMax++)
        {
            result.push_back(C*(*iterMin) + (1 - C)*(*iterMax));
        }
        std::cout << std::endl << "Check result" << std::endl;
        print(result);
        std::cout << std::endl << "Result of HW method: " << *max_element(result.begin(), result.end());
    }
    else
    {
        std::cout << std::endl << "C value not valid" << std::endl;
    }
}

template<typename T> bool checkP(std::vector<T> matrix)
{
  double sum = 0;
  bool result;
  for(auto value : matrix)
    {
      sum += value;
    }
  if(sum < 1 || sum == 1)
    {
      result = true;
    }
  else
    {
      result = false;
    }
  return result;
}

template<typename T> void BL(std::vector<T>X, std::vector<double>P)
{
  std::cout << std::endl << "BL method";
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
