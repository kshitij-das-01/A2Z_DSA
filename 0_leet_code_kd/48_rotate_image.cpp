#include <bits/stdc++.h>
using namespace std;

// Solution 1
class Solution {
public:
    void transpose(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i+1; j < matrix[0].size(); j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }

    void reverseRow(vector<int> &v)
    {
        int l = 0, r = v.size() - 1;

        while (l < r)
        {
            int temp = v[l];
            v[l] = v[r];
            v[r] = temp;
            l++;
            r--;
        }
    }

    void rotate(vector<vector<int>>& matrix) 
    {
        // transpose the matrix
        transpose(matrix);

        for (int i = 0; i < matrix.size(); i++)
        {
            reverseRow(matrix[i]);
        }
    }
};