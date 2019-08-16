#include <bits/stdc++.h>
using namespace std;
int branch(vector<int> A[], int **V, int m, int n, int i, int j)
{
    if (i - 1 >= 0)
    {
        if (A[i - 1][j] && !V[i - 1][j])
        {
            V[i - 1][j] = 1;
            branch(A, V, m, n, i - 1, j);
        }
    }
    if (j - 1 >= 0)
    {
        if (A[i][j - 1] && !V[i][j - 1])
        {
            V[i][j - 1] = 1;
            branch(A, V, m, n, i, j - 1);
        }
    }
    if (i - 1 >= 0 && j - 1 >= 0)
    {
        if (A[i - 1][j - 1] && !V[i - 1][j - 1])
        {
            V[i - 1][j - 1] = 1;
            branch(A, V, m, n, i - 1, j - 1);
        }
    }
    if (i + 1 < m && j - 1 >= 0)
    {
        if (A[i + 1][j - 1] && !V[i + 1][j - 1])
        {
            V[i + 1][j - 1] = 1;
            branch(A, V, m, n, i + 1, j - 1);
        }
    }
    if (i + 1 < m)
    {
        if (A[i + 1][j] && !V[i + 1][j])
        {
            V[i + 1][j] = 1;
            branch(A, V, m, n, i + 1, j);
        }
    }
    if (i + 1 < m && j + 1 < n)
    {
        if (A[i + 1][j + 1] && !V[i + 1][j + 1])
        {
            V[i + 1][j + 1] = 1;
            branch(A, V, m, n, i + 1, j + 1);
        }
    }
    if (j + 1 < n)
    {
        if (A[i][j + 1] && !V[i][j + 1])
        {
            V[i][j + 1] = 1;
            branch(A, V, m, n, i, j + 1);
        }
    }
    if (i - 1 >= 0 && j + 1 < n)
    {
        if (A[i - 1][j + 1] && !V[i - 1][j + 1])
        {
            V[i - 1][j + 1] = 1;
            branch(A, V, m, n, i - 1, j + 1);
        }
    }
}
int findIslands(vector<int> A[], int m, int n)
{
    int c = 0;
    int **V = new int *[m];
    for (int i = 0; i < m; i++)
    {
        V[i] = new int[n];
        memset(V[i], 0, n * sizeof(int));
    }
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] && !V[i][j])
            {
                V[i][j] = 1;
                c++;
                branch(A, V, m, n, i, j);
            }
        }
    }
    return c;
}
int main()
{
    int m, n, i, j, t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        vector<int> v[m];
        for (i = 0; i < m; i++)
        {
            vector<int> temp(n);
            v[i] = temp;
            for (j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        cout << findIslands(v, m, n) << endl;
    }
    return 0;
}