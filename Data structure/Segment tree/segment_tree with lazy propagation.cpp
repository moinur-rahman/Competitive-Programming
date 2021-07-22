#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define mx 100005

int arr[mx];
struct info
{
    li prop,sum;
}tree[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=arr[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e||j<b)
        return 0;
    if(b>=i&&e<=j)
        return tree[node].sum+carry*(e-b+1);
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}

void update(int node,int b,int e,int i,int j,li x)
{
    if(i>e||j<b)
        return;
    if(b>=i&&e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

void print(struct info a[],int n)
{
    For1(i,n)
    cout<<a[i].sum<<" ";
    cout<<"\n";
    For1(i,n)
    cout<<a[i].prop<<" ";
    cout<<"\n";

}

int main()
{
    int n;
    cin>>n;
    For1(i,n)
    cin>>arr[i];
    init(1,1,n);
    print(tree,3*n);
    update(1,1,n,2,4,8);
   print(tree,3*n);
   cout<<query(1,1,n,1,3,2);
}

