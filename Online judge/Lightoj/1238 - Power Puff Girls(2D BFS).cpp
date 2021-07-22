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

char v[25][25];
bool visited[25][25];
int level[25][25];
int dr[]={0,-1,0,1};
int dc[]={1,0,-1,0};
int m,n;

void bfs(int x,int y)
{
queue<pair<int,int> >Q;
Q.push(mp(x,y));
visited[x][y]=true;
level[x][y]=0;

while (!Q.empty())
{
int f=Q.front().first;
int s=Q.front().second;
Q.pop();
For0(i,4)
{
  x=f+dr[i];
  y=s+dc[i];
 if(x>=0&&x<m&&y>=0&&y<n&&(!visited[x][y])&&v[x][y]!='#'&&v[x][y]!='m')
 {
   visited[x][y]=true;
   level[x][y]=level[f][s]+1;
   Q.push(mp(x,y));
 }
}
}

}

int main ()
{ IOS fi
int T;
cin>>T;
For0(k,T)
{  memset(visited,0,sizeof(visited));
  memset(level,0,sizeof(level));
  cin>>m>>n;
  int ax,ay,bx,by,cx,cy,hx,hy;
  For0(i,m)
  For0(j,n)
  {cin>>v[i][j];
  if(v[i][j]=='a')
  ax=i,ay=j;
  else if(v[i][j]=='b')
  bx=i,by=j;
  else if(v[i][j]=='c')
  cx=i,cy=j;
  else if(v[i][j]=='h')
  hx=i,hy=j;
  }
  bfs(hx,hy);
  cout<<"Case "<<k+1<<": "<<max(max(level[ax][ay],level[bx][by]),level[cx][cy])<<endl;
}
}
