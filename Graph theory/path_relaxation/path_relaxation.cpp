#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
typedef long long ll;

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
#define cs 10005

//#ifndef ONLINE_JUDGE
//fi;
//fo;
//#endif
vector<pair<int,int> > v[cs];
int dist[cs];

void bfsmodified(int s,int n)
{
  queue<int> Q;
  for(int i=1;i<=n;++i)
  dist[i]=(int)INFINITY;  ///infinity value inserted .... infinity is double value we converted into integer
  Q.push(s);
  dist[s]=0;

  while (!Q.empty())
  {
   int u=Q.front();
    Q.pop();
    for (int i = 0; i < v[u].size() ; i++)  ///adjacent node of u
    {    int f=v[u][i].first;

      if( dist[u]+v[u][i].second<dist[f] )
       {
         dist[f] = dist[u] + v[u][i].second ;
         Q.push(f);
       }
    }
  }
}


int main ()
{   fi
    IOS
    int n,a,b,w,e;
    cin>>n>>e;    ///input node and edge
    For0(i,e)
    {   cin>>a>>b>>w;
        v[a].push_back(make_pair(b,w));     /// weight of path a to b is 5 and a---b = w
    }
    bfsmodified(1,n);
    cout<<dist[3]<<endl;  ///distance print out of source node 1 to 4
}
