#include <iostream>
#include <vector>
#include <algorithm>
const int priceNew = 49000, priceOld = 25000;
static int diff = priceNew - priceOld;
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
void MinMax(vector<vector<T>> matrix)
{
    cout << "MinMax method" << endl;
    vector<T> min;
    for(auto value : matrix)
    {
        min.push_back(*min_element(value.begin(), value.end()));
    }
    cout << "Check min:" << endl;
    print(min);
    cout << endl << "Result of MinMax method: " << *max_element(begin(min), end(min)) << endl;
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
bool checkP(vector<double>P)
{
    double sum = 0;
    bool result;
    for(auto value : P)
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
    //cout << endl << "Summary of P(x) = " << sum << endl;
    return result;
}
template <typename T>
void Sav(vector<vector<T>> matrix)
{
    vector<vector<T>>mat1;
    vector<T>mat2;
    T max = 0;
    cout << endl << "Savage method" << endl;
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
    cout << "\nCheck mat1 \n";
    print(mat1);
    for(auto value : mat1)
    {
        mat2.push_back(*max_element(value.begin(), value.end()));
    }
    cout << "Mat2 check: " << endl;
    print(mat2);
    cout << endl << "Result of Savage method: " << *min_element(mat2.begin(), mat2.end());
}
template <typename T>
void HW(vector<vector<T>>matrix, double C)
{
    vector<T> min, max, result;
    vector<vector<T>> mat1;
    cout << endl << "HW method" << endl;
    if(C <= 1 && C >= 0)
    {
        for(unsigned int i = 0; i < matrix.size(); i++)
        {
            mat1.push_back(getCol(matrix, i));
        }
        cout << "Check mat1" << endl;
        print(mat1);
        for(auto value : mat1)
        {
            max.push_back(*max_element(value.begin(), value.end()));
            min.push_back(*min_element(value.begin(), value.end()));
        }
        cout << endl << "Check min:" << endl;
        print(min);
        cout << endl << "Check max:" << endl;
        print(max);
        for(auto iterMin = min.begin(), iterMax = max.begin();
                 iterMin != min.end(), iterMax != max.end();
                 iterMin++, iterMax++)
        {
            result.push_back(C*(*iterMin) + (1 - C)*(*iterMax));
        }
        cout << endl << "Check result" << endl;
        print(result);
        cout << endl << "Result of HW method: " << *max_element(result.begin(), result.end());
    }
    else
    {
        cout << endl << "C value not valid" << endl;
    }
}
template <typename T>
vector<vector<double>> getDepends(vector<T>row, vector<T>col)
{
    vector<vector<double>> result;
    return result;
}
template <typename T>
void BL(vector<T>X, vector<double>P)
{
    cout << endl << "BL method";
    if(checkP(P))
    {
        cout << ": " << endl;
        cout << "P(x) is valid" << endl;
    }
    else
    {
        cout << " is failed. Please check P(x)" << endl;
    }
}

int main() {
    vector<vector<int>> matrix{
            {15,10,0,-6,17},
            {3,14,8,9,2},
            {1,5,14,20,-3},
            {7,19,10,2,0}
    };
    vector<int>X{
            100, 150,
            200, 250,
            300
    };
    vector<double>P{
            0.1, 0.15,
            0.25, 0.3,
            0.2
    };
    cout << "InitMatrix:" << endl;
    print(matrix);
    MinMax(matrix);
    Sav(matrix);
    HW(matrix, 0.21);
    BL(X, P);
    return 0;
}