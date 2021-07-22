#include<bits/stdc++.h>
using namespace std;
             
typedef long long ll;
typedef pair<ll,ll> Pi;
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
#define cs 505
#define pi acos(-1)
#define INF (int)INFINITY
void in()
{
     #ifndef ONLINE_JUDGE
          freopen("input.txt", "r", stdin);
          freopen("output.txt", "w", stdout);
     #endif
}

vector<pair<ll,ll> > v[cs];
ll dist[cs];
ll parent[cs];
ll inf=1e17;

void dijkstra(ll s,ll n)
{
  priority_queue<Pi,vector<Pi>,greater<Pi> > Q;///distance and source
  for(ll i=1;i<=n;++i)
  dist[i]=inf;
  Q.push(make_pair(0,s));
  dist[s]=0;
  while (!Q.empty())
  {
   ll u=Q.top().second;

    Q.pop();
    for (ll i = 0; i < v[u].size() ; i++)  ///adjacent node of u
    {    ll f=v[u][i].first;   /// .first is the second node and .second is the weight

      if( dist[u]+v[u][i].second<dist[f] )
       {
         dist[f] = dist[u] + v[u][i].second ;
         Q.push(make_pair(dist[f],f));
         parent[f]=u;
       }
    }
  }
}

int b1,b2;
double ans;
void solve(int n)
{
  b1=1;
  b2=-1;
  ans=0.0;

  for(int i=1;i<=n;++i)
  {
    if(dist[i]>ans&&dist[i]!=inf)
    {
      ans=dist[i];
      b1=i;
    }
  }
   for(int i=1;i<=n;i++)
   {
     for(int j=0;j<v[i].size();++j)
     {
       int x=v[i][j].first;
       double y=v[i][j].second;

       double u=dist[i];
       double v=dist[x];
       if(u<v) swap(u,v);
       double last=u+(y-(u-v))/2.0;
       if(last>ans)
       {
         ans=last;
         b1=min(x,i);
         b2=max(x,i);
       }
     }
   }
}

int main()
{in();
int n,m,tc=0;
while (cin>>n>>m,n||m)
{ 
  memset(v,0,sizeof v);
  int a,b,w;
  For0(i,m)
  {
    cin>>a>>b>>w;
    v[a].pb(mp(b,w));
    v[b].pb(mp(a,w));
  }

  dijkstra(1,n);

 solve(n);

 cout<<"System #"<<++tc<<endl;

 printf("The last domino falls after %.1lf seconds, ",ans);
 if(b2==-1)
 cout<<"at key domino "<<b1<<"."<<endl;
else
cout<<"between key dominoes "<<b1<<" and "<<b2<<"."<<endl;
cout<<endl;

}



}