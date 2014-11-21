#ifndef API
#define API
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T> void print(T cont)
{
    for(auto value : cont)
    {
      std::cout << value << "\t";
    }
}

template <typename T> void print(std::vector<std::vector<T>> vec)
{
    for(auto value : vec)
    {
        print(value);
	std::cout << std::endl;
    }
}

template <typename T> std::vector<T> getCol(std::vector<std::vector<T>>matrix, unsigned int col)
{
    std::vector<T>tmp;
    for(auto value : matrix)
    {
        tmp.push_back(*(value.begin()+col));
    }
    return tmp;
}

template <typename T> std::vector<std::vector<T>> getRowColMatrix(std::vector<std::vector<T>> matrix)
{
  std::vector<std::vector<T>> tmp;
  for(unsigned int i = 0; i <= matrix.capacity(); i++)
    {
      tmp.emplace_back(getCol(matrix, i));
    }
  tmp.shrink_to_fit();
  return tmp;
}

#endif
