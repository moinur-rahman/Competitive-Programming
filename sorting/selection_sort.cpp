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

void selection_sort(int A[],int n)
{
    int i,j,index_min,temp;

    for(i=0;i<n-1;i++)
    {
        index_min=i;

        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[index_min])
            index_min=j;
        }
        if(index_min!=i)
        {
            temp=A[i];
            A[i]=A[index_min];
            A[index_min]=temp;
        }
    }
}

int main()
{
int arr[]={2,9,6,7,1,3,4,5,8,10};

int l=sizeof(arr)/sizeof(arr[0]);

selection_sort(arr,l);

For0(i,10)
cout<<arr[i]<<" ";

}