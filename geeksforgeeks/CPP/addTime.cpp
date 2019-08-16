#include<bits/stdc++.h>
using namespace std;
class t{
    int h,m,s;
    public:void set(){
        cout<<"Enter time in hh mm ss format"<<endl;
        cin>>h>>m>>s;
    }
    void dis(){
        cout<<h<<" : "<<m<<" : "<<s<<endl;
    }
    void add(t ob1,t ob2){
        int v;
        s=ob1.s+ob2.s;
        if(s>=60)
        {
            s=s%60;
            v=1;
        }
        else
            v=0;
        m=v+ob1.m+ob2.m;
        if(m>=60){
            m=m%60;
            v=1;
        }
        else
            v=0;
        h=ob1.h+ob2.h+v;
        if(h>23)
        {
            h=24-h;
        }
    }
};
int main(){
    t ob1,ob2,ob3;
    ob1.set();
    ob2.set();
    ob3.add(ob1,ob2);
    ob3.dis();
    return 0;
}