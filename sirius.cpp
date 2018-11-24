//Any improvements appreciated,raise an issue

/*Sirius's school's students were taken for a field trip. As a fun activity all the students were asked to sit in a circle. Also each student was asked to pick his favorite whole number.

According to Sirius, a number is good if it has exactly 3 positive divisors. Sirius conisiders the seating arrangement good if

If it is possible to select atleast 3 students who all have "good" favorite numbers.
The arc distance between all adjacent pairs of students should be same.
In other words, if the students are vertices of a polygon, the polygon should be regular.
There are a total of N students.

Input Format

First line of input contains one integer N. Following line contains N space sperated integers which denote the favourite numbers of respective students.

Constraints

1 <= N <= 100000

0 <= Favorite Number <= 10^10

Output Format

Print "YES" without quotes if it is possible to make a good selection otherwise print "NO" without quotes.*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int divi(int x)
{   
    int i,c=0;
    for(i=1;i<=(int)sqrt(x);i++) {
        if(x%i==0)
        {
            if(x/i==i)
                c++;
            else
                c=c+2;
        } 
    }
    return c;
}
/*int check(int a[],int n)
{
    int diff;
    diff=a[1]-a[0];
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]-a[i]!=diff)
            return 0;
    }
    return 1;
}*/
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int c=0,n,i,diff;
    int y=-1;
    cin>>n;
    int arr[n],m[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if((divi(arr[i]))==3)
        {
            c++;
            m[++y]=i;
            if(y==1)
            { 
                diff=m[1]-m[0];
            } 
            else if(y>1 && m[y]-m[y-1]!=diff) 
            { 
                cout<<"NO"<<endl;
                return 0; 
            } 
            else
            { 
                continue; 
            } 
        }
    }
    
    if(c>=3 && (n-m[y]+m[0])==diff)
    {
        cout<<"YES"<<endl;
    }
    else 
        cout<<"NO"<<endl;  
    return 0;
}
