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

int partition(int A[],int low,int high)
{
    int pivot, i, j, t;

    pivot = A[high];

    for(i = low-1, j = low; j< high; ++j)
    {
        if(A[j]<pivot)
        {
            i++;
            t=A[j];

            A[j]=A[i];

            A[i]=t;
        }
    }

    t = A[high];

    A[high]=A[i+1];

    A[i+1]=t;

    return i+1;
}

void quick_sort(int A[],int low,int high)
{
    if(low>=high)
        return;

    int p;

    p = partition(A,low,high);

    quick_sort(A,low,p-1);

    quick_sort(A,p+1,high);
}

int main()
{
//fi
IOS

int A[] = {1,5,6,3,5,8,7,2,9};

int n=sizeof(A)/sizeof(A[0]);

quick_sort(A,0,n);

For0(i,n)
cout<<A[i]<<" ";
}
