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

void merge(int A[],int left,int mid,int right)
{
    
    int index_a, index_l, index_r;

    int size_left, size_right;

    size_left = mid-left+1;

    size_right = right - mid;

    int L[size_left], R[size_right];

    for(int i=0;i<size_left;i++)
    L[i]=A[left+i];

    for(int i=0;i<size_right;i++)
    R[i] = A[mid+1+i];

    index_l = 0;
    index_r = 0;

    for(index_a=left;index_l<size_left && index_r < size_right; index_a++)
    {
        if(L[index_l]<R[index_r])
        {
        A[index_a] = L [index_l];
        index_l++;
        }
        else 
        {
            A[index_a]=R[index_r];
            index_r++;
        }
    }

    while(index_l<size_left)
    {
        A[index_a]=L[index_l];
        index_l++;
        index_a++;
    }
    while(index_r<size_right)
    {
        A[index_a]=R[index_r];
        index_r++;
        index_a++;
    }

}


void merge_sort(int A[],int left,int right)
{
    if(left>=right)
    return;

    int mid = left + (right-left)/2;

    merge_sort(A,left,mid);

    merge_sort(A,mid+1,right);

   merge(A,left,mid,right);
}

int main()
{
int arr[]={2,9,6,7,1,3,4,5,8,10};

int l=sizeof(arr)/sizeof(arr[0]);

merge_sort(arr,0,l-1);

For0(i,l)
cout<<arr[i]<<" ";

}