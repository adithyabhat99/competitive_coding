// asked in CodeArgon 2020
#include <bits/stdc++.h>
using namespace std;
void allPairsShortestPath(int **allPairs, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (allPairs[i][k] + allPairs[k][j] < allPairs[i][j])
                    allPairs[i][j] = allPairs[i][k] + allPairs[k][j];
            }
        }
    }
}
vector<int> minimumPartyCost(vector<int> &costPerCity, vector<vector<int>> &roads)
{
    int n = costPerCity.size();
    int **allPairs = new int *[n];
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        allPairs[i] = new int[n];
        for(int j=0; j<n; j++)
            allPairs[i][j] = 999;
        allPairs[i][i] = 0;
        result.push_back(costPerCity[i]);
    }
    for (int i = 0; i < roads.size(); i++)
    {
        allPairs[roads[i][0] - 1][roads[i][1] - 1] = roads[i][2];
        allPairs[roads[i][1] - 1][roads[i][0] - 1] = roads[i][2];
    }
    allPairsShortestPath(allPairs, n);
    for (int i = 0; i < result.size(); i++)
    {
        int min = result[i];
        for (int j = 0; j < result.size(); j++)
        {
            if (((2 * allPairs[i][j]) + result[j]) < min)
            {
                min = (2 * allPairs[i][j]) + result[j];
            }
        }
        result[i] = min;
    }
    return result;
}
int main()
{
    vector<int> costPerCity1{10, 2, 4, 15, 30};
    vector<vector<int>> roads1{{1, 2, 3}, {3, 4, 5}, {4, 5, 4}};

    vector<int> ans1 = minimumPartyCost(costPerCity1, roads1);
    for (auto a : ans1)
        cout << a << " ";
    cout << endl;


    vector<int> costPerCity2{4, 1, 10, 15};
    vector<vector<int>> roads2{{2, 3, 2}, {3, 4, 2}, {1, 3, 3}};

    vector<int> ans2 = minimumPartyCost(costPerCity2, roads2);
    for (auto a : ans2)
        cout << a << " ";
    cout << endl;
    return 0;
}