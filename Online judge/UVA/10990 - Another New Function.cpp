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
#define cs 2000005
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

void sievephi(ll n)
{
    int i,j;
    /// initialization
    for(ll i=1;i<=n;++i)
        phi[i]=i;

    phi[1]=1;
    mark[1]=1;

    for(ll i=2;i<=n;i++)
    {
        if(!mark[i])
            for(j=i;j<=n;j+=i)
        {
            mark[j]=1;
            phi[j]=phi[j]/i*(i-1);
        }
      //  phi[i]+=phi[i-1];
    }
}

ll man(ll n)
{
    if(n==1)
    return 0;
    return man(phi[n])+1;
}
ll al[cs];
void solve()
{  al[1]=1;
   for(ll i=2;i<cs;++i)
   {al[i]=man(i);
   al[i]+=al[i-1];
   }
}

int main()
{   IOS;
   
    sievephi(cs);
     solve();
    in();

    int t;   
     cin>>t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<al[b]-al[a-1]<<endl;
    }
}
