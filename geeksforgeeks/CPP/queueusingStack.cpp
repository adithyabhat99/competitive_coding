//Queue using 2 stacks
#include<iostream>
#include<stack>
using namespace std;
class stacks{
    stack<int> s1;
    stack<int> s2;
public:void push(int x){
        s1.push(x);
    }
    void pop(){
        if(s1.empty()){
            cout<<"Empty\n";
            return;
        }
        while(!s1.empty()){ //this is swapping of s1 & s2
            s2.push(s1.top());
            s1.pop();
        }
        cout<<"Popped "<<s2.top()<<endl;
        s2.pop();
        swap(s1,s2);
    }
    void dis(){
        if(s1.empty()){
            cout<<"Empty\n";
            return;
        }
        for(stack <int> i=s1;!i.empty();i.pop()){ //dsplaying from top to bottom
            cout<<i.top()<<" ";
        }
        cout<<endl;
    }
};
int main(){
    stacks s;
    int ch,i;
    do{
        cout<<"Enter choice\n";
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter number\n";
            cin>>i;
            s.push(i);
        }
        else if(ch==2){
            s.pop();
        }
        else if(ch==3)
        {
            s.dis();
        }
        else
            return 1;
    }while(1);
    return 1;
}