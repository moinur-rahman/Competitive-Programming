#include<bits/stdc++.h>
using namespace std;

typedef long long int li;

#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)

template <typename T>
T BigMod(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main()
{
    int a,b,M;

    cin>>a>>b>>M;

    cout<<BigMod(a,b,M)<<endl;

}
