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
int a[105][105], dp[105][105];
void solve()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (!n && !m)
            break;
        For1(i, n)
        {
            For1(j, m)
            {
                cin >> a[i][j];
            }
        }

        For1(i, n)
        {
            For1(j, m)
            {
                dp[i][j] = dp[i][j - 1] + a[i][j];
            }
        }
        For1(i, n)
        {
            For1(j, m)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j];
            }
        }
        int ans = 0;
        For1(i, n)
        {
            For1(j, m)
            {
                For0(k, i)
                {
                    For0(l, j)
                    {
                        int sz = dp[i][j] - dp[i][l] - dp[k][j] + dp[k][l];
                        if (sz == 0)
                        {
                            ans = max(ans, (i - k) * (j - l));
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
int main()
{
    in();
    IOS;
    int t = 1;
    // cin >> t;
    For1(i, t)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}