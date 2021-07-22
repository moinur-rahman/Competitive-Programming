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

int main()
{
//fi
IOS
///in counting sort we must have to know the input value range
int arr[]={3,4,1,6,2,4,9,7,8,4,2,1};

int l=sizeof(arr)/sizeof(arr[0]);

int range = 10; ///the range of the input in 1 to 10;

int count[range+1];

memset(count,0,sizeof(count));
int x;
for(int i=0;i<l;i++)
{
    x=arr[i];
    count[x]++;
}

for(int i=0;i<range+1;i++)
cout<<"index : "<<i<<", value : "<<count[i]<<endl;
}
