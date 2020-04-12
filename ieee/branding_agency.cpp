// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// class trie
// {
//     public:
//     int ends;
//     trie *next[26];
//     trie()
//     {
//         for(int i=0;i<26;i++)
//         {
//             next[i]=NULL;
//         }
//         ends=0;
//     }
// };
// trie *insert(string s,trie *head)
// {
//     if(s.size()==0) return head;
//     trie *h=head;
//     for(int i=0;i<s.length();i++)
//     {
//         if(h->next[(int)97-s[i]])
//         {
//             h=h->next[(int)97-s[i]];
//         }
//         else
//         {
//             h->next[(int)97-s[i]]=new trie();
//             h=h->next[(int)97-s[i]];
//         }
//     }
//     h->ends++;
//     return head;
// }
// void getMax(trie *head,int &M)
// {
//     if(!head)
//     {
//         return;
//     }
//     M=max(M,head->ends);
//     for(int i=0;i<26;i++)
//     {
//         if(head->next[i]!=NULL)
//         {
//             getMax(head->next[i],M);
//         }
//     }
// }
// int slogans(string s)
// {
//     trie *head=new trie();
//     for(int i=0;i<s.size();i++)
//     {
//         for(int j=i;j<s.size();j++)
//         {
//             head=insert(s.substr(i,j+1),head);
//         }
//     }
//     int M=0;
//     getMax(head,M);
//     return M;
// }
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
//     int n;
//     string s;
//     cin>>n>>s;
//     cout<<slogans(s)<<endl;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// bool isThereTwice(string s)
// {
//     map<string,int> mp;
//     mp[s]=INT_MIN;
//     for(int i=0;i<s.length();i++)
//     {
//         for(int j=i;j<s.length();j++)
//         {
//             string sub=s.substr(i,j);
//             mp[sub]++;
//             if(mp[sub]>=2)
//                 return true;    
//         }
//     }
//     return false;
// }
// void slogans(string s,unordered_map<string,bool> &done,int &M,int &t)
// {
//     if(done[s]==true) return;
//     done[s]=true;
//     unordered_map<string,bool> done2;
//     for(int i=0;i<s.length();i++)
//     {
//         for(int j=0;j<s.length();j++)
//         {
//             string sub=s.substr(i,j+1);
//             if(done2[sub]==false && isThereTwice(sub)==true)
//             {
//                 M=max(t+1,M);
//                 slogans(sub,done,M,t);
//             }
//             done2[sub]=true;
//         }
//     }
//     t++;
// }
// int main()
// {
//     int n;
//     string s;
//     cin>>n>>s;
//     int M=0,t=0;
//     unordered_map<string,bool> done;
//     slogans(s,done,M,t);
//     cout<<t<<endl;
//     return 0;
// }