#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> adi;
    int n,x;
    cout<<"Enter the size of the vector\n";
    cin>>n;
    cout<<"Enter "<<n<<" elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        adi.push_back(x);
    }
    cout<<"Elements are\n";
    for(int i : adi)
    cout<<i<<" ";
    cout<<endl;  
    cout<<"Size of the vecor is "<<adi.size()<<endl;
    return 0;
}