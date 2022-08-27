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

int binary_search(int A[],int n,int x)
{
    int left,right,mid;

    left=0;
    right=n-1;

    while(left<=right)
    {
        mid=(left+right)/2;

        if(A[mid]==x)
            return mid;

        if(A[mid]<x)
            left=mid+1;
        else right=mid-1;
    }
  return -1;
}

int main()
{
    int arr[]={2,3,6,7,10,13,14,15,18};



    int l=sizeof(arr)/sizeof(arr[0]);

    cout<<binary_search(arr,l,7);
}
