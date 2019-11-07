//https://practice.geeksforgeeks.org/problems/max-rectangle/1/?ref=self
//This uses the problem largest_rectangular_area_in_histogram.cpp
int maxHist(int a[],int n)
{
    stack<int>s;
    int max_area=0,area,i=0;
	    while(i<n)
	    {
	        if(s.empty()||a[s.top()]<=a[i])
	        {
	            s.push(i++);
	        }
	        else
	        {
	            int t=s.top();
	            s.pop();
	            area=a[t]*(s.empty()?i:(i-s.top()-1));
	            max_area=max(area,max_area);
	        }
	    }
	    while(!s.empty())
	    {
	        int t=s.top();
            s.pop();
            area=a[t]*(s.empty()?i:(i-s.top()-1));
            max_area=max(area,max_area);
	    }
	  return max_area;
}
int maxArea(int M[MAX][MAX],int n,int m)
{
    //Your code here
    int res=maxHist(M[0],m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j])
            {
                M[i][j]+=M[i-1][j];
            }
        }
        res=max(res,maxHist(M[i],m));
    }
    return res;
}