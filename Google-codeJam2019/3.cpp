#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,l,x=1,i,j;
    cin>>t;
    while(x<=t){
        cin>>l>>n;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        int c=0,d=0,f=0;
        int m=a[0];
        while(!(m%2)){
            m>>=1;
            c++;
        }
        if(c>1){
            d=c;
            c=2;
            f=1;
        }

        for(i=3;i<=sqrt(m) && f==0;i++){
            c=0;
            while(!(m%i)){
                c++;
                m/=i;
            }
            if(c>1){
                d=c;
                c=i;
                f=1;
            }
        }
        if(m>2 && f==0){
            d=m;
            c=a[0]/d;  
        }
        int b[n+1],cc[n+1];
        cc[0]=b[0]=c;
        c=d;
        for(i=1;i<n;i++){
            cc[i]=b[i]=c;
            c=a[i]/b[i];
        }
        cc[n]=b[n]=a[n-1]/b[n-1];

        sort(b,b+n+1);
        map<int,char> mp;
        int q=65;
        for(i=0;i<=n;i++)
        {
            int y=b[i];
            if(mp.find(y)==mp.end()){
            mp[y]=(char)q;
            q++;
            }
        }
        cout<<"Case #"<<x<<": ";
        for(i=0;i<=n;i++){
            int y=cc[i];
            cout<<mp[y];
        }
        cout<<endl;
        x++;
    }
    return 0;
}