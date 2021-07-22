#include<bits/stdc++.h>
using namespace std;

typedef long long int li;
#define For0(i,n) for(int i=0;i<n;i++)
#define For1(i,n) for(int i=1;i<=n;i++)

#define mx 100005

bool marked[mx];
void sieve(int n) {

  for (int i = 2; i * i <= n; i++)
    {
    if (marked[i] == false)
    { // i is a prime
      for (int j = i * i; j <= n; j += i) {///amr root over n porjnto check korlei hoice jacce tai i*i
        marked[j] = true;
      }
    }
  }
}

bool isPrime(int n) {

  if (n < 2) return false;

  return marked[n] == false;
}

int main()
{
int n;
cin>>n;
sieve(n);
if(isPrime(n))
cout<<"Prime"<<endl;
else
cout<<"Not Prime"<<endl;
}
