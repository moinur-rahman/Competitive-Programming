#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define mx 100005
//#ifndef ONLINE_JUDGE
//fi;
//fo;
//#endif

int weight[mx],value[mx];
int dp[1005][1005];
int knapSack(int W,int n)
{
if(dp[W][n]!=-1)
return dp[W][n];
if(n==0||W==0)
 return 0;

 if(weight[n]>W)
    return knapSack(W,n-1);

 else
    { dp[W][n]=max(value[n]+knapSack(W-weight[n],n-1),knapSack(W,n-1));
    return dp[W][n];
    }
}

int main()
{   fi
    IOS
    int T;
    cin>>T;
    while(T--)
    {
   
    int x;
    cin>>x;

    For1(i,x) ///value 1 to x
    {
        cin>>value[i]>>weight[i];
    }
   int t,W;
   cin>>t;
    int sum=0;

   For0(i,t)
    {  memset(dp,-1,sizeof(dp));
       cin>>W;
        sum+=knapSack(W,x);
    }
   cout<<sum<<endl;
    }
}

