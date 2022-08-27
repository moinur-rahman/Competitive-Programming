#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

int egcd(int a,int b,int &x,int &y)
{
    if(a==0)
    {
        x=0,y=1;
        return b;
    }
    int x1,y1;

    int d=egcd(b%a,a,x1,y1);

    x=y1-(b/a)*x1;

    y=x1;

    return d;
}

int main()
{
  int a,b,x,y;
  cin>>a>>b;
  cout<<egcd(a,b,x,y)<<endl;
  cout<<x<<" "<<y<<endl;
}
