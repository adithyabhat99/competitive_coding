//Not a competitive coding question
/*You might think private variables cannot be accessed out of the class,but it can be accessed
Private access specifier is actually not a thing for security , it is just for preventing accidental
changes to important data members while building packages or frameworks or APIs */
#include<iostream>
using namespace std;
class data{
    int x,y;
    public:
    data()
    {
        x=0;
        y=10;
    }
    void out()
    {
        cout<<x<<"\t"<<y<<endl;
    }
};
int main()
{
    data o;
    cout<<"Before hacking value of x and yis ";
    o.out();
    int *p=(int *)&o;
    (*p)=100;
    *(p+1)=100;
    cout<<"After hacking value of x and is ";
    o.out();
    return 0;
}
