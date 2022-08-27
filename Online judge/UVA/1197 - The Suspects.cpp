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
#define cs 500005
#define pi acos(-1)
#define INF (int)INFINITY

void in()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int parent[cs];

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

void solve()
{
    int n, m;
    while (1)
    {
        cin >> n >> m;
        if (!n && !m)
        {
            break;
        }
        memset(parent, 0, sizeof parent);
        For1(i, n)
        {
            make_set(i);
        }
        int ans = 0;
        For0(i, m)
        {
            int k;
            cin >> k;

            int a[k], mn = INT_MAX;
            For0(j, k)
            {
                cin >> a[j];
                mn = min(a[j], mn);
            }
            For0(j, k)
            {
                union_sets(mn, a[j]);
            }
        }
        For1(j, n)
        {
            if (find_set(j) == find_set(0))
            {
                ans++;
                // cout << j << " " << ans << endl;
            }
        }

        cout << ans + 1 << endl;
    }
}

int main()
{
    in();
    IOS int t = 1;
    // cin >> t;
    For1(i, t)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}