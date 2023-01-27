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
string s[30];
int dp[30][30];
void solve()
{
    cin >> s[0];

    int row = s[0].length();

    s[1] = '#' + s[0];

    for (int i = 2; i <= row; i++)
    {
        cin >> s[i];
        s[i] = '#' + s[i];
    }

    For1(i, row)
    {
        For1(j, row)
        {
            dp[i][j] = dp[i][j - 1] + (s[i][j] == '1');
        }
    }
    For1(j, row)
    {
        For1(i, row)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j];
        }
    }
    int mx = 0;
    For1(i, row)
    {
        For1(j, row)
        {
            For0(k, i)
            {
                For0(l, j)
                {
                    if (dp[i][j] - dp[k][j] - dp[i][l] + dp[k][l] == (i - k) * (j - l))
                        mx = max(mx, dp[i][j] - dp[k][j] - dp[i][l] + dp[k][l]);
                }
            }
        }
    }
    cout << mx << endl;
    // For1(i, row)
    // {
    //   For1(j, row)
    //   {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << mx << endl;
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
        if (i != t)
        {
            cout << endl;
        }
    }
}