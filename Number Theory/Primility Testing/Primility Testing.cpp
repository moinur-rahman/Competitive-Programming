#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
#define For0(i,n) for(int i=0;i<n;i++)
#define For1(i,n) for(int i=1;i<=n;i++)

#define mx 100005

bool prim(ull x) {

  if (x < 2) return false;
   
   if(x%2==0 || x%3==0||x%5==0 ) return false;
   
   
  for (ull  i = 5; i * i <= x; i=i+6)
    {
    if (x % i == 0||(x+2)%i==0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
int tc;
cin>>tc;
while (tc--)
{
ull n;
cin>>n;
if(Prim(n)||n==2||n==3||n==5)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;

}

}
