//https://practice.geeksforgeeks.org/problems/square-root/1
long long int floorSqrt(long long int x) 
{
    // Your code goes here  
    if(x==0) return 0;
    if(x==1) return 1;
    long long int low=0,high=x;
    while(low<=high)
    {
        long long int mid=(low+high)/2;
        if(mid==(x/mid))
        {
            return mid;
        }
        else if(mid<(x/mid))
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return (long long int)floor(high);
}