#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> Pi;
typedef map<ll, ll> mi;

template <class T>
T nrem(T x, T y) { return ((x % y) + y) % y; }
const ll M = 1e9 + 7;
ll mod(ll x) { return ((x % M + M) % M); }

#define loop(i, a, b) for (int i = a; i <= b; ++i)
#define rloop(i, a, b) for (int i = a; i >= b; --i)
#define For0(i, n) for (int i = 0; i < n; ++i)
#define For1(i, n) for (int i = 1; i <= n; ++i)
#define Forl0(i, n) for (ll i = 0; i < n; ++i)
#define Forl1(i, n) for (ll i = 1; i <= n; ++i)
#define fi freopen("input.txt", "r", stdin);
#define fo freopen("output.txt", "w", stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define cs 1000005
#define pi acos(-1)
#define INF (int)INFINITY

void in()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<ll> prime;

void primeFactor(ll n)
{

    if (n % 2 == 0)
    {
        prime.pb(2);
        while (n % 2 == 0)
            n /= 2;
    }

    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            prime.pb(i);
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 2)
        prime.pb(n);
}

void solve()
{
    ll a, b, m;
    cin >> a >> b >> m;
    if (a > b)
        swap(a, b);
    ll dif = b - a, sum = 0;
    if (dif == 1)
    {
        cout << m + 1 << endl;
        return;
    }
    if (m == 0)
    {
        if (__gcd(a, b) == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;

        return;
    }
    if (a == b)
    {
        if (a == 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return;
    }
    prime.clear();
    primeFactor(dif);

    // if(prime[0]>m)
    // {
    //   ll cnt = 0;
    //  for (ll i = 0; i <= m; i++)
    //   {
    //       if (__gcd(a + i, b + i) == 1)
    //       {
    //           cnt++;
    //           //cout<<a+i<<" "<<b+i<<endl;
    //       }
    //   }
    //  cout<<cnt<<endl;
    // return;
    // }

    ll sz = prime.size();
    for (ll i = 0; i < sz; i++)
    {
        ll base = m / prime[i], ano = 0;
        for (ll j = 0; j < i; j++)
        {
            ano += base / prime[j];
        }
        //cout<<prime[i]<<" "<<ano<<endl;
        sum += base - ano;
    }
    // if(__gcd(a,b)==1)
    // cout<<m - sum +1 << endl;
    // else
    // cout<<m - sum -1<< endl;
    if (__gcd(a, b) == 1)
        m++;
    cout << m - sum << endl;
    For0(i, prime.size())
    {
        cout << prime[i] << " ";
    }
}

int main()
{
    in();
    int t = 1;
    cin >> t;
    For1(i, t)
    {
        cout << "Case " << i << ": ";
        solve();
    }
}