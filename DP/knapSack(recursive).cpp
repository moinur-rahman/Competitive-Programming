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


int knapSack(int W, int wt[], int val[], int n)
{

// Base Case
if (n == 0 || W == 0)
    return 0;

// If weight of the nth item is more
// than Knapsack capacity W, then
// this item cannot be included
// in the optimal solution
if (wt[n-1] > W)
    return knapSack(W, wt, val, n-1);

// Return the maximum of two cases:
// (1) nth item included
// (2) not included
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1) );
}

int main()
{
    int x,W;
    cin>>x>>W;
    int value[x],weight[x];
    For0(i,x) ///value 1 to x
    {
        cin>>value[i]>>weight[i];
    }
    cout<<knapSack(W,weight,value,x)<<endl;
}

