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

vector <pi> v[30001];
bool visited[30001];
int mx,p,dis1[30001],dis2[300001];

void dfs(int s,int dis[])
{
if(visited[s])
return;
if(mx<dis[s])
  {mx=dis[s];
  p=s;
  }
visited[s]=true;
for(int i=0;i<v[s].size();++i)
{ 
  
  if(dis[v[s][i].first]==-1)
  {
  dis[v[s][i].first]=dis[s]+v[s][i].second;
  }
  dfs(v[s][i].first,dis);
}
}

int main ()
{
  IOS fi
  int q;
  scanf("%d",&q);
  For1(k,q)
  {
  int n;
  scanf("%d",&n);
  int a,b,w;
  For0(i,n-1)
  {
  scanf("%d%d%d",&a,&b,&w);
  v[a].pb(mp(b,w));
  v[b].pb(mp(a,w));
  }
  
  memset(visited,false,sizeof(visited));
  memset(dis1,-1,sizeof(dis1));
  dis1[0]=0;
  mx=0;
  dfs(0,dis1);
   int a1=p;
  
  memset(visited,false,sizeof(visited));
  memset(dis1,-1,sizeof(dis1));
  dis1[a1]=0;
  mx=0;
  dfs(a1,dis1);
  int a2=p;
  
  memset(visited,false,sizeof(visited));
  memset(dis2,-1,sizeof(dis2));
  dis2[a2]=0;
  dfs(a2,dis2);
  printf("Case %d:\n",k);
   For0(i,n)
  printf("%d\n",max(dis1[i],dis2[i]));
  memset(v,0,sizeof(v));
  }
}
