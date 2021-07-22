#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef map<ll,ll> mi;

#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define Forl0(i,n) for(ll i=0;i<n;++i)
#define Forl1(i,n) for(ll i=1;i<=n;++i)
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cs 1000000
#define pi acos(-1)
#define INF (int)INFINITY
void in()
{
        	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
	      freopen("output.txt", "w", stdout);
	         #endif
}


ll phi[cs],mark[cs];
ll ans[cs];
void sievephi(ll n)
{
    ll i,j;
    /// initialization
    for(int i=1;i<=n;++i)
        phi[i]=i;

    phi[1]=1;
    mark[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!mark[i])
            for(j=i;j<=n;j+=i)
        {
            mark[j]=1;
            phi[j]=phi[j]/i*(i-1);
        }
    }


    for(ll i=1;i<=n;++i)
    {
     for(ll j=i;j<=n;j+=i)
     {
        ans[j]+=i*phi[i];
     }   
    }
}
int main()
{   IOS;
    in();
   
   sievephi(cs);
   int t;
   cin>>t;

   while (t--)
   {
      ll a;
      cin>>a;
      
      ll answer=(ans[a]+1)*a/2;
      cout<<answer<<endl;
   }
   
   
}
