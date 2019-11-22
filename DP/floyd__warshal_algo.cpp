//https://www.techiedelight.com/pairs-shortest-paths-floyd-warshall-algorithm
#include <bits/stdc++.h>
using namespace std;
void printPath(int **path, int i, int j)
{
    if (path[i][j] == i)
        return;
    printPath(path, i, path[i][j]);
    cout << path[i][j] << " ";
}
void printSolution(int **cost, int **path, int n)
{
    cout << "Cost matix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Path from each node to others\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (path[i][j] != -1 && i != j)
            {
                cout << i << " - " << j << " ";
                printPath(path, i, j);
                cout << endl;
            }
        }
    }
}
void floyd_marshal(int **a, int n)
{
    int **path = new int *[n], **cost = new int *[n];
    for (int i = 0; i < n; i++)
    {
        cost[i] = new int[n];
        path[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = a[i][j];
            if (i == j)
                path[i][j] = 0;
            else if (cost[i][j] != 999)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    }
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    path[i][j] = path[k][j];
                }
            }
            if (cost[i][i] < 0)
            {
                cout << "There is a negative weight cycle\n";
                return;
            }
        }
    }
    printSolution(cost, path, n);
}
int main()
{
    int n;
    cin >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    floyd_marshal(a, n);
    return 0;
}