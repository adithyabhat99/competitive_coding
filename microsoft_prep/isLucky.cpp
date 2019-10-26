//https://www.geeksforgeeks.org/lucky-numbers/
//see comments in geeksforgeeks for explanation
#include<iostream>
using namespace std;
bool isLucky(int n)
{
    static int counter=2;
    if(counter>n)
        return true;
    if(n%counter==0)
        return false;
    n-=n/counter;
    counter++;
    return isLucky(n);
}
int main()
{
    int n;
    cin>>n;
    cout<<isLucky(n)<<endl;
}