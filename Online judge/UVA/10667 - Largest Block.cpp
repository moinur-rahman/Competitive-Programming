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
long a[205][205], dp[205][205];
void solve()
{
    int n, s;
    cin >> s >> n;
    memset(a, 0, sizeof a);
    For0(i, n)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        for (int j = r1; j <= r2; j++)
        {
            for (int k = c1; k <= c2; k++)
            {
                a[j][k] = 1;
            }
        }
    }
    // For1(i, s)
    // {
    //   For1(j, s)
    //   {
    //     cout << a[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            dp[i][j] = a[i][j] + dp[i][j - 1];
        }
    }

    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            dp[i][j] += dp[i - 1][j];
        }
    }
    // For1(i, s)
    // {
    //   For1(j, s)
    //   {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    int ans = 0;
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            For0(k, i)
            {
                For0(l, j)
                {
                    if (dp[i][j] - dp[k][j] - dp[i][l] + dp[k][l] == 0)
                    {
                        ans = max(ans, (i - k) * (j - l));
                    }
                }
            }
        }
    }
    cout << ans << endl;
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