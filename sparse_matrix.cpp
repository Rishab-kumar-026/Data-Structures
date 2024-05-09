#include <iostream>
using namespace std;
int main()
{
    int i, j, size, k = 0;
    int sparse_matrix[3][4] = {
        {0, 0, 5, 0},
        {4, 0, 0, 0},
        {0, 2, 0, 1}};

    size = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (sparse_matrix[i][j] != 0)
            {
                size++;
            }
        }
    }

    int new_matrix[3][size];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (sparse_matrix[i][j] != 0)
            {
                new_matrix[0][k] = i;
                new_matrix[1][k] = j;
                new_matrix[2][k] = sparse_matrix[i][j];
                k++;
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < size; j++)
        {
            cout << new_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}