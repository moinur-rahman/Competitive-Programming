#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define mx 100005

vector<int> adj[mx];
int visited[mx];
int arr[mx];

void dfs(int t)
{
    if(visited[t])return;
    visited[t]=1;
    cout<<t<<" ";
    for(int i=0;i<adj[t].size();i++)
        dfs(adj[t][i]);
}

int main()
{   freopen("input.txt","r",stdin);
    int n,e,x,y;
    cin>>n>>e;   ///n for node and e for edge
    For1(i,n)
    cin>>arr[i];  ///node input
    For1(i,e)
    {
        cin>>x>>y;
    adj[x].push_back(y);   ///edge input
    adj[y].push_back(x);
    }
    For1(i,n)
    {
        if(visited[arr[i]]==0)
            dfs(arr[i]);       ///applying dfs on each node;
    }

}

