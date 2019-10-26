// https://www.hackerrank.com/challenges/components-in-graph/problem
// Using Union-Find Algorithm.
#include <bits/stdc++.h>
using namespace std;
int findParent(int n,int parent[],int i)
{
    if(parent[i]==i)
        return i;
    return parent[i]=findParent(n,parent,parent[i]);
}
void Union(int u,int v,int parent[],int s[],int n)
{
    int x=findParent(n,parent,u);
    int y=findParent(n,parent,v);
    if(x==y) return;
    parent[x]=y;
    s[y]+=s[x];
}
vector<int> componentsInGraph(vector<vector<int>> gb) {
    int n=gb.size();
    int parent[2*(n)+1],s[2*(n)+1];
    for(int i=0;i<=2*n;i++)
    {
        parent[i]=i;
        s[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        Union(gb[i][0],gb[i][1],parent,s,2*n);
    }
    int Max=INT_MIN,Min=INT_MAX;
    for(int i=1;i<=2*n;i++)
    {
        int x=s[findParent(2*n,parent,i)];
        Max=max(Max,x);
        if(x>1 && x<Min) Min=x;
    }
    vector<int> v(2);
    v[0]=Min==1?2:Min,v[1]=Max;
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> SPACE = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
        fout << SPACE[SPACE_itr];

        if (SPACE_itr != SPACE.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}