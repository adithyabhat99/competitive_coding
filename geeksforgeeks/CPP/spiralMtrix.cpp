#include<iostream>
using namespace std;
int main(){
int m,i,j;
cin>>m;
int a[m][m];
for(i=0;i<m;i++){
for(j=0;j<m;j++)
cin>>a[i][j];
}
int l=0,r=m,d=m,u=0;
int D=1;
while(l<r || u<d){
switch(D){
case 1:for(i=l;i<r;i++)
        cout<<a[u][i]<<" ";
        D=2;
        u++;
        break;
case 2:for(i=u;i<d;i++)
        cout<<a[i][r-1]<<" ";
        D=3;
        r--;
        break;
case 3:
        for(i=r-1;i>=l;i--)
        cout<<a[d-1][i]<<" ";
        D=4;
        d--;
        break;
case 4:for(i=d-1;i>=u;i--)
        cout<<a[i][l]<<" ";
        D=1;
        l++;
        break;
}
}
cout<<endl;
return 0;
}
