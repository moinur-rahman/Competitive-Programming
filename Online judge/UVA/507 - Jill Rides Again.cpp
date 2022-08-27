#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> Pi;
typedef map<ll, ll> mi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
#define cs 20005
#define pi acos(-1)
#define INF (int)INFINITY

void in()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int a[cs], dp[cs], k = 0;

void solve()
{
    int n;
    cin >> n;

    n--;

    For1(i, n)
    {
        cin >> a[i];
    }
    int mx = INT_MIN;
    For1(i, n)
    {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0)
            dp[i] = 0;
        mx = max(mx, dp[i]);
    }
    int start = -1, stop = -1, len = 0, last = 0;
    For1(i, n)
    {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0)
            dp[i] = 0, last = i;
        if (dp[i] == mx)
        {
            if (i - last > len)
            {
                len = i - last;
                start = last + 1;
                stop = i + 1;
            }
        }
    }
    // cout << endl;
    if (mx == 0)
    {
        cout << "Route " << ++k << " has no nice parts" << endl;
        return;
    }
    // cout << endl;
    // cout << len << endl;
    // cout << start << " " << stop << endl;
    cout << "The nicest part of route " << ++k << " is between stops " << start << " and " << stop << endl;
}
int main()
{
    in();
    IOS;
    int t = 1;
    cin >> t;
    For1(i, t)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}