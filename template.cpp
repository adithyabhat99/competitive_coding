//Demonstrating standard template library in C++
#include <vector>
#include <set>
#include<iostream>
#include <utility>
#include <map>
#include<algorithm>
using namespace std;
bool f(int x,int y)
{
   
    return x>y;
}
void vect() 
{
    vector <int> a;
    
    a.push_back(20);
    a.push_back(100);
    a.push_back(30);

    for(auto x:a)
    cout<<x<<endl;
    sort(a.begin(),a.end(),f); //sort functon can be called with 2 arguments too
    //here we explicitly specify to sort in descending order by usinf f() function

    vector <int> ::iterator s;  //two ways of creating iterator, using auto keyword is easier and better
    for(s=a.begin();s!=a.end();s++)
    cout<<*s<<endl;

}
void sets() //sets in c++ are always sorted and accessible in nlogn time using find() function
{
    int x;
    set <int> a;
    a.insert(10);
    a.insert(5);
    for(auto x:a)
    cout<<x<<endl;
}
int fact(int n)
{
    if(n==0) return 1;
    return n*fact(n-1);
}
void pairs_sets()
{
    pair <int,int> a; //included under utility library
    set <pair<int,int>> s; //set of pairs
    pair <int,int> x; 
    int n,nn;

    a.first=10;
    a.second=20;
    cout<<a.first<<" "<<a.second<<endl;
    
    cout<<"Enter numbers\n"; cin>>nn;
    while(nn--){
        cin>>n;
        x.first=n;
        x.second=fact(n);
        s.insert(x);
    }
    for(auto x:s)
        cout<<x.first<<" "<<x.second<<endl;  //sorted numbers along with thier factorials
}
void maps()
{
    map <int ,string> m;
    int n,x; string name;
    cout<<"Enter number of students\n";
    cin>>n;
    cout<<"Enter usn and name\n";
    while(n--)
    {
        cin>>x;
        cin>>name;
        m.insert(pair<int,string>(x,name));
    }
    cout<<"Details of students:\n";
    for(auto a:m)
    {
        cout<<a.first<<" "<<a.second<<endl;
    }
}
int main()
{
    vect();
    sets();
    pairs_sets();
    maps();
}