//Given 2 dates,print the number of days between them
#include<bits/stdc++.h>
using namespace std;
class date
{
    int d,m,y;
    public:int DaysMonth(int x,date ob){
        switch(x){
            case 1:return 31;
            case 2:if(leap(ob.y)) return 29;
            else return 28;
            case 3:return 31;
            case 4:return 30;
            case 5:return 31;
            case 6:return 30;
            case 7:return 31;
            case 8:return 31;
            case 9:return 30;
            case 10:return 31;
            case 11:return 30;
            case 12:return 31;
        }
        return 0;
    }
    void set(){
        cout<<"Enter date in format dd mm yy\n";
        cin>>d>>m>>y;
    }
    int DaysYear(int x){
        if(leap(x)) return 366;
        return 365;
    }
    int leap(int x)
    {
        if((x%4==0 && x%100!=0)||x%400==0)
            return 1;
        return 0;
    }
    int diff(date ob1,date ob2){
        int m1=0,m2=0,d1,d2,y=0;
        for(int i=1;i<ob1.m;i++){
            m1+=DaysMonth(i,ob1);
        }
        for(int i=1;i<ob2.m;i++){
            m2+=DaysMonth(i,ob2);
        }
        d1=abs((m1+ob1.d)-DaysYear(ob1.y));
        d2=m2+ob2.d;
        y+=d1+d2;
        if(ob1.y==ob2.y && ob1.m==ob2.m) {
            return abs(ob2.d-ob1.d);
        }
        else if(ob1.y==ob2.y){
            d1=m1+ob1.d;
            d2=m2+ob2.d;
            return abs(d2-d1);
        }
        for(int i=ob1.y+1;i<ob2.y;i++){
            y+=DaysYear(i);
        }
        return y;
    }
};
int main(){
    date ob1,ob2,ob3;
    ob1.set();
    ob2.set();
    cout<<"Number of days between entered dates are "<<ob3.diff(ob1,ob2)<<endl;
    return 0;
}