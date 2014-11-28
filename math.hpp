#ifndef MATH_HPP
#define MATH_HPP
#include "api.hpp"

template<typename T> std::vector<T>getMinVector(std::vector<std::vector<T>>matrix)
{
  std::vector<T>min;
  for(auto value : matrix)
    {
      min.emplace_back( *min_element(begin(value), end(value)) );
    }
  return min;
}

template<typename T> std::vector<T> getMaxVector(std::vector<std::vector<T>> matrix)
{
  std::vector<T>max;
  for(auto value : matrix)
    {
      max.emplace_back(*max_element(begin(value), end(value)));
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
    T max = 0;

    std::cout << std::endl << "!======Savage method======!" << std::endl;
    for(auto& value : mat1) {
        max = *max_element(begin(value), end(value));
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
           mat3.emplace_back(getCol(mat1, i));
	    }
    std::cout << "Check mat3: " << std::endl;
    print(mat3);
    std::vector<T>mat2(getMaxVector(mat3));
    std::cout << "Mat2 check: " << std::endl;
    print(mat2);
    std::cout << std::endl << "Result of Savage method: " << *min_element(begin(mat2), end(mat2)) << std::endl;

}
template<typename T> void HW(std::vector<std::vector<T> > matrix, double C)
  {
    std::cout << std::endl << "!======HW method======!" << std::endl;
    std::cout << "C = " << C << std::endl;
    if(C <= 1 && C >= 0)
    {
        std::vector<T> min(getMinVector(matrix));
        std::vector<T> max(getMaxVector(matrix));
        std::vector<double> result;
        double tmp = 0;

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

#endif
