/*
Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:

0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges 
So we have to determine what is the minimum time required so that all the oranges become rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two integers r and c, where r is the number of rows and c is the number of columns in the array a[]. Next line contains space separated r*c elements each in the array a[].

Output:
Print an integer which denotes the minimum time taken to rot all the oranges.(-1 if it is impossible).

Constraints:
1<=T<=100
1<=r<=100
1<=c<=100
0<=a[i]<=2

Example:
Input:
2
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1 
3 5
2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

Output:
2
-1
*/

#include <bits/stdc++.h>
using namespace std;
struct ele{
    int x,y;
};
bool isvalid(int i,int j,int r,int c){
    if(i>=0 && j>=0 && i<r && j<c) return true;
    return false;
}
bool isdelemeter(ele temp){
    if(temp.x==-1 && temp.y==-1) return true;
    return false;
}
bool checkall(int **a,int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]==1)
                return true;
        }
    }
    return false;
}
int rot(int **a,int r,int c){
    queue<ele> q;
    ele temp;
    int ans=0,i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]==2)
            {
                temp.x=i; 
                temp.y=j;
                q.push(temp);
            }
        }
    }
    temp.x=-1; 
    temp.y=-1; 
    q.push(temp);
    while(!q.empty()){
        bool flag=false;
        while(!isdelemeter(q.front())){
            temp=q.front();
            if(isvalid(temp.x+1,temp.y,r,c) && a[temp.x+1][temp.y]==1){
                if(!flag){
                    ans++; 
                    flag=true;
                }
                a[temp.x+1][temp.y]=2; 
                temp.x++;
                q.push(temp); 
                temp.x--;
            }
            if(isvalid(temp.x-1,temp.y,r,c) && a[temp.x-1][temp.y]==1)
            {
                if(!flag){
                    ans++; 
                    flag=true;
                }
                a[temp.x-1][temp.y]=2; 
                temp.x--;
                q.push(temp); 
                temp.x++;
            }
            if(isvalid(temp.x,temp.y+1,r,c) && a[temp.x][temp.y+1]==1)
            {
                if(!flag) {
                    ans++; 
                    flag=true;
                }
                a[temp.x][temp.y+1]=2; 
                temp.y++;
                q.push(temp); 
                temp.y--;
            }
            if(isvalid(temp.x,temp.y-1,r,c) && a[temp.x][temp.y-1]==1)
            {
                if(!flag) {
                    ans++; 
                    flag=true;
                }
                a[temp.x][temp.y-1]=2; 
                temp.y--;
                q.push(temp); 
                temp.y++;
            }
            q.pop();
        }
        q.pop();
        if(!q.empty()){
            temp.x=-1; 
            temp.y=-1;
            q.push(temp);
        }
    }
    return checkall(a,r,c)?-1:ans;
}
int main() {
	//code
	int t,r,i,j,c;
	cin>>t;
	while(t--){
	    cin>>r>>c;
	    int **a=new int*[r];
	    for(i=0;i<r;i++) 
	        a[i]=new int[c];
	    for(i=0;i<r;i++){
	        for(j=0;j<c;j++)
	            cin>>a[i][j];
	        
	    }
	    cout<<rot(a,r,c)<<endl;
	}
	return 0;
}

