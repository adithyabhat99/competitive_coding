//https://practice.geeksforgeeks.org/problems/box-stacking/1
#include<bits/stdc++.h>
using namespace std;
struct box
{
    int h,w,d;
};
int compare (const void *a, const void * b) 
{ 
    return ( (*(box *)b).d * (*(box *)b).w ) - 
           ( (*(box *)a).d * (*(box *)a).w ); 
}
int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
    box b[3*n];
    int index=0;
    for(int i=0;i<n;i++)
    {
        b[index].h=height[i];
        b[index].d=max(width[i],length[i]);
        b[index].w=min(width[i],length[i]);
        index++;
        b[index].h=width[i];
        b[index].d=max(height[i],length[i]);
        b[index].w=min(height[i],length[i]);
        index++;
        b[index].h=length[i];
        b[index].d=max(width[i],height[i]);
        b[index].w=min(width[i],height[i]);
        index++;
    }
    n=3*n;
    qsort(b,n,sizeof(b[0]),compare);
    int msh[n];
    for(int i=0;i<n;i++)
        msh[i]=b[i].h;
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(b[i].d<b[j].d && b[i].w<b[j].w && msh[i]<msh[j]+b[i].h)
                msh[i]=msh[j]+b[i].h;
                
    int M=INT_MIN;
    for(int i=0;i<n;i++)
        M=max(M,msh[i]);
    return M;
}