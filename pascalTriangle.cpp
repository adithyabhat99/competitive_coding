//Print pascal triangle
#include<iostream>
using namespace std;
int main(){
    int rows,i,j,c,space;
    cout<<"Enter number of rows\n";
    cin>>rows;
    for(i=0;i<rows;i++){
        for(space=1;space<=rows-i;space++)
            cout<<" ";
        for(j=0;j<=i;j++){
            if(j==0||i==0)
                c=1;
            else
                c=c*(i-j+1)/j;
            cout<<c<<" ";
        }
        cout<<endl;
    }
}