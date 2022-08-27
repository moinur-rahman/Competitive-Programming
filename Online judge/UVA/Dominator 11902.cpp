#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define OJ
#define mx 1000005

int adj[105][105];
bool visited[105];
bool dominate[105][105];
int n;
void dfs(int t)
{
    if(visited[t])return;
    visited[t]=1;
    //cout<<t<<" ";
    for(int i=0;i<n;i++)
        if(adj[t][i])
        dfs(i);
}
void printline(int n)
{
    for(int i=1;i<=2*n+1;++i)
        if(i==1||i==(2*n+1))
        cout<<"+";
    else cout<<"-";
    cout<<"\n";
}
int main ()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    For1(k,T)
    {int a;
    cin>>n;
    For0(i,n)
    For0(j,n)
    {
     cin>>adj[i][j];
    }
     memset(dominate,false,sizeof(dominate));
     dominate[0][0]=1;
     for(int i=1;i<n;++i)
     {
      dominate[0][i]=true;
      memset(visited,false,sizeof(visited));
      visited[i]=true;
      dfs(0);
      for(int j=0;j<n;j++)
        if(!visited[j])
        dominate[i][j]=true;
      dominate[i][i]=true;
     }
     memset(visited,false,sizeof(visited));
     dfs(0);
    cout<<"Case "<<k<<":\n";
     printline(n);
     For0(i,n)
     {
         For0(j,n)
     {
         if(dominate[i][j]&&visited[j])
            cout<<"|Y";
         else cout<<"|N";
     }
     cout<<"|\n";
     printline(n);
     }
    }
}
