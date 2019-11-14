//https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams/0
#include <bits/stdc++.h>
using namespace std;
int cmp(int cP[],int cW[])
{
    for(int i=0;i<256;i++)
    {
        if(cP[i]!=cW[i])
            return false;
    }
    return true;
}
void count(string text,string word,int &c)
{
    int cP[256],cW[256];
    memset(cP,0,sizeof(cP));
    memset(cW,0,sizeof(cW));
    int n=text.size(),m=word.size();
    for(int i=0;i<m;i++)
    {
        cP[word[i]]++;
        cW[text[i]]++;
    }
    for(int i=m;i<n;i++)
    {
        if(cmp(cP,cW))
        {
            c++;
        }
        cW[text[i]]++;
        cW[text[i-m]]--;
    }
    if(cmp(cP,cW))
    {
        c++;
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string text,word;
	    cin>>text>>word;
	    int x=0;
	    count(text,word,x);
	    cout<<x<<endl;
	}
	return 0;
}