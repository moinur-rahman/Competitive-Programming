#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
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
#define cs 100005
#define pi acos(-1)
#define INF (int)INFINITY
void in()
{
        	#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
	    	//freopen("output.txt", "w", stdout);
	         #endif
}

ll dp[cs];

int main()
{IOS

ll n;
while(1)
{cin>>n;
if(!n)
return 0;
For1(i,n)
{
cin>>dp[i];
dp[i]+=dp[i-1];
if(dp[i]<0)
dp[i]=0;
}
ll mx=0;
For1(i,n)
{
mx=max(mx,dp[i]);
}
if(mx)
cout<<"The maximum winning streak is "<<mx<<"."<<endl;
else
cout<<"Losing streak."<<endl;
}
}


