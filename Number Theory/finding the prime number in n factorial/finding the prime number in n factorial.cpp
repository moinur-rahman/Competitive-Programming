///finding the prime in n factorial///

#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

int find_prime(int n,int p)
{

 if((n/p)==0)
    return 0;
  int sum=n/p;
  int d=find_prime(n,p*p);
  return sum+d;
}

int main()
{
  int n,p;  ///n is the number of factorial and p is the prime number
  cin>>n>>p;
  cout<<find_prime(n,p)<<endl;
}
