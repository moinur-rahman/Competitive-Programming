
#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

char arr[105][105];
int visited[105][105];
 int n,m;
//#define mx 10000005
void dfs(int x,int y)
{   if(visited[x][y])
    return;
    if(x<1||x>m||y<1||y>n)
        return;
     visited[x][y]=1;
    if(arr[x][y]=='*')
        return;
    dfs(x+1,y);
    dfs(x,y+1);
    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x-1,y-1);
    dfs(x+1,y+1);
    dfs(x+1,y-1);
    dfs(x-1,y+1);

}

int main()
{  //freopen("moin.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    while(cin>>m>>n)
    {
    memset(visited,0,sizeof(visited));
    if(m==0)
        break;
    int d=0;
    For1(i,m)
    For1(j,n)
    {
        cin>>arr[i][j];
    }
    For1(i,m)
    {For1(j,n)
    {
        if(arr[i][j]=='@'&&visited[i][j]==0)
          {
              dfs(i,j);
              d++;
          }
    }
    }
   cout<<d<<endl;
}
}
