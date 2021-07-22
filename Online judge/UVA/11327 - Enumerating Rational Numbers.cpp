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
#define cs 1000006
#define pi acos(-1)
#define INF (int)INFINITY
void in()
{
        	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
	      freopen("output.txt", "w", stdout);
	         #endif
}


ll phi[1000006],mark[1000006];

void sievephi(ll n)
{
    int i,j;
    /// initialization
    for(ll i=1;i<=n;++i)
        phi[i]=i;

    phi[1]=2;
    mark[1]=1;

    for(ll i=2;i<=n;i++)
    {
        if(!mark[i])
            for(j=i;j<=n;j+=i)
        {
            mark[j]=1;
            phi[j]=phi[j]/i*(i-1);
        }
        phi[i]+=phi[i-1];
    }
}
/*int phi(int n)
{
    int ret=n;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {   
                n/=i;
            }
          
            ret -= ret/i;
        }
    }

    if(n>1)
    {   
        ret -= ret/n;
    }

    return ret;
}*/

int main()
{   IOS;
    phi[0]=1;
   
    sievephi(cs);
    in();
    ll a;   
     cin>>a;
    while (a)
    {
    //For0(i,a+1)
   // cout<<phi[i]<<endl;
    
    ll lo=lower_bound(phi,phi+cs,a)-phi;
    ll hi=upper_bound(phi,phi+cs,a)-phi;
   // cout<<phi[1000000]<<endl;
    ll rem=a-phi[lo-1];
   // cout<<rem<<endl;
   // cout<<lo<<endl;

    if(a==1)
    cout<<0<<"/"<<1<<endl;
    else if(a==2)
    cout<<1<<"/"<<1<<endl;

    else if(lo==hi)
    {   ll i;
        for(i=1;rem;++i)
        if(__gcd(lo,i)==1)
        rem--;
        
       
        cout<<i-1<<"/"<<lo<<endl;
    }
    else cout<<lo-1<<"/"<<lo<<endl;
    cin>>a;
    }
}
