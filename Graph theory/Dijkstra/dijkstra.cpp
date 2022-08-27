#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
typedef long long ll;
typedef pair<ll,ll> Pi;

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

vector<pair<ll,ll> > v[cs];
ll dist[cs];
ll parent[cs];

void printPath(ll j)
{
    if(j!=1)
    printPath(parent[j]);  ///recursive way of print

    printf("%d ", j);
}

void dijkstra(ll s,ll n)
{
  priority_queue<Pi,vector<Pi>,greater<Pi> > Q;///distance and source
  for(ll i=1;i<=n;++i)
  dist[i]=1e18;
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


int main ()
{   fi
    IOS
    ll n,a,b,w,e;
    cin>>n>>e;    ///input node and edge
    For0(i,e)
    {   cin>>a>>b>>w;
        v[a].push_back(make_pair(b,w));
       v[b].push_back(make_pair(a,w));
    /// weight of path a to b is 5 and a---b = w
    }
    dijkstra(1,n);

    if(dist[n]==1e18)
        return cout<<-1,0;
    printPath(n);

}
