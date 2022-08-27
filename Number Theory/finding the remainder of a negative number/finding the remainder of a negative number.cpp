///finding the modulus of a negative number
#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

//#define mx 10000005

int main()
{ //freopen("moin.txt","r",stdin);
int x,y;
cin>>x>>y;

int mod=((x%y)+y)%y; ///adding the divisor to the remainder and then modulus with the divisor then
                      ///the remainder is the real remainder of a negative number
cout<<mod<<endl;
}
