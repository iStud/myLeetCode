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

// vector<vector<int>> generateMatrix(int n)
// {
//     vector<vector<int>> res(n, vector<int>(n, 0));
//     int top = 0;
//     int right = n - 1;
//     int bottom = n - 1;
//     int left = 0;
//     int num = 1;
//     int end = n * n;
//     while (num <= end)
//     {
//         for (int i = left; i <= right; i++)
//             res[top][i] = num++; //i代表列---从左到右
//         top++;

//         for (int i = top; i <= bottom; i++)
//             res[i][right] = num++; //i代表行---从上到下
//         right--;

//         for (int i = right; i >= left; i--)
//             res[bottom][i] = num++; //i代表列---从右到左
//         bottom--;

//         for (int i = bottom; i >= top; i--)
//             res[i][left] = num++; //i代表行---从下到上
//         left++;
//     }
//     return res;
// }

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
