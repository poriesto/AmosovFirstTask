#ifndef API
#define API
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void print(T cont)
{
    for(auto value : cont)
    {
        cout << value << "\t";
    }
}
template <typename T>
void print(vector<vector<T>> vec)
{
    for(auto value : vec)
    {
        print(value);
        cout << endl;
    }
}
template <typename T>
vector<T> getCol(vector<vector<T>>matrix, unsigned int col)
{
    vector<T>tmp;
    for(auto value : matrix)
    {
        tmp.push_back(*(value.begin()+col));
    }
    return tmp;
}
template <typename T>
vector<vector<double>> getDepends(vector<T>row, vector<T>col)
{
    vector<vector<double>> result;
    return result;
}

#endif
