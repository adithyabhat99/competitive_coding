#include <bits/stdc++.h>
using namespace std;
int main()
{
    int b, n;
    cin >> b >> n;
    vector<int> v;
    if (n == 0 || b==0 || b==1)
    {
        if(b==1)
        {
            for(int i=1;i<=n;i++)
                cout<<1;
            cout<<endl;
        }
        else 
            cout << 0 << endl;
        return 0;
    }
    while (n != 0)
    {
        v.push_back(n % b);
        n = n / b;
    }
    vector<int>::iterator it=v.end()-1;
    while(*it==0)
    {
        it--;
    }
    reverse(v.begin(), it+1);
    for (vector<int>::iterator i=v.begin();i!=it+1;i++)
        cout << *i;
    cout << endl;
}