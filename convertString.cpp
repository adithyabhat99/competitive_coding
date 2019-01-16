    /*You are provided two strings A and B. You have to transform string A into string B in minimum number of steps. Only one operation is allowed, chose any of the characters in string A and place it in the front of A. If its not possible to transform string A into string B then print -1 otherwise print the minimum number of steps required.

    Note: All the characters in the string are lowercase English characters.

    Input :

    The first line contains integer T, denoting number of test cases. Then T test cases follow . 
    The first line of each test case contains two space separated  strings A and B.

    Output:
    Print in a new line the answer of each test case .

    Constraints :

    1<=T<=100

    1<=|A|,|B|<=10^5

    Example:
    Input:
    2
    bcad abcd
    abdd dbad

    Output :
    1
    2
    */
    #include<iostream>
    #include<string.h>
    using namespace std;
    int convert(string a,string b){
        int n,m,result=0,i,j;
        n=a.length();
        m=b.length();
        if(m!=n) { 
            return -1; 
        }
        i=m-1;
        j=n-1;
        while(i>=0 && j>=0){
            while(a[i]!=b[j] && i>=0){
            	int x=j-1;
                while(x>=0)
                {
                	if(b[x]==a[i] && i>=0)
                	{
                		result++;
                		i--;
                		break;
                	}
                	x--;
                }
            }
            if(a[i]==b[j]){
                i--;
                j--;
            }
        }
        return result;
    }
    int main(){
        int t;
        string a,b;
        int p;
        cin>>t;
        while(t--){
            cin>>a>>b;
            p=convert(a,b);
            cout<<p<<endl;
        }
        return 0;
    }