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
#define INF (int)INFINITY
//#ifndef ONLINE_JUDGE
//fi;
//fo;
//#endif

int p[55],sol[55];
vector<int> v[55];
int stand[55];

int main()
{ 
int q;
cin>>q;
For0(k,q)
{
memset(v,0,sizeof v);
int n;
cin>>n;

int id,s,tp,m,sum=0,a;
For0(i,n)
{  sum=0;
    cin>>id>>s>>tp>>m;
    For0(j,m)
    {
    cin>>a;
    v[id].pb(a);
    sum+=a;
    }
    p[id]=sum+tp;
    sol[id]=s+m;
}


For0(i,n)
cin>>stand[i];

int flag=0;
For1(i,n)
{  
int sz=v[stand[i]].size();

while(sz&&((sol[stand[i]]>sol[stand[i-1]])||((sol[stand[i]]==sol[stand[i-1]])&&(p[stand[i]]<p[stand[i-1]]))))
{
    sol[stand[i]]--;
    p[stand[i]]-=v[stand[i]][sz-1];
    sz--;
}
if((sol[stand[i]]>sol[stand[i-1]])||((sol[stand[i]]==sol[stand[i-1]])&&(p[stand[i]]<p[stand[i-1]])))
{cout<<"Case "<<k+1<<": "<<"Say no to rumour >:"<<endl;
flag=1;
break;
}
}
if(flag)
continue;
cout<<"Case "<<k+1<<": "<<"We respect our judges :)"<<endl;
}
}