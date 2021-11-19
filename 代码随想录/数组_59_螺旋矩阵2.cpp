#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void printArr(vector<vector<int>> v)
{
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {

        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> generateMatrix(int value)
{

    // 二维数组
    vector<vector<int>> v(value, vector<int>(value, 0));

    int end = value * value;
    int left = 0;
    int right = value - 1;
    int top = 0;
    int bottom = value - 1;
    int num = 1;

    while (num <= end)
    {

        for (int i = left; i <= right; i++)
        {
            v[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            v[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left; i--)
        {
            v[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--)
        {
            v[i][left] = num++;
        }

        left++;
    }
    return v;
}

int main()
{

    vector<vector<int>> v = generateMatrix(3);
    printArr(v);

    system("pause");
    return 0;
}
