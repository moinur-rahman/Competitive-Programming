#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define mx 100005
int main()
{
    int x;
    set<int>s;
    cin>>x;
    for(int i=1;i*i<=x;i++)
    if(x%i==0)
        {s.insert(i);
     s.insert(x/i);
    }for(auto it=s.begin();it!=s.end();it++)
        cout<<*it<<" ";
}
