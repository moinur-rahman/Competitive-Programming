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

int parent[100];
vector<int> adj[100];

void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
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
    int n;
    while (cin >> n)
    {
        memset(parent, 0, sizeof parent);

        memset(adj, 0, sizeof adj);
        int m;
        cin >> m;

        string wake;
        cin >> wake;

        For1(i, 30)
        {
            make_set(i);
        }

        union_set(1, 2);
        union_set(2, 3);

        map<char, int> index;

        int cnt = 0;

        For0(i, wake.size())
        {
            index[wake[i]] = (++cnt);
        }

        For0(i, m)
        {
            string s;
            cin >> s;

            if (!index[s[0]])
            {
                index[s[0]] = ++cnt;
            }
            if (!index[s[1]])
            {
                index[s[1]] = ++cnt;
            }
            adj[index[s[0]]].pb(index[s[1]]);
            adj[index[s[1]]].pb(index[s[0]]);
        }
        int current_wake = 3, previos_wake = -1, ans = 0;
        // For1(i, n)
        // {
        //   cout << parent[i] << " ";
        // }
        // cout << endl;
        while (previos_wake < current_wake)
        {

            previos_wake = current_wake;
            ans++;
            vector<int> awakeNeighbours;
            for (auto it : index)
            {
                int u = it.second;

                if (find_set(u) == 1)
                {
                    continue;
                }

                int awake_neighbours = 0;

                for (int i = 0; i < adj[u].size(); i++)
                {
                    if (find_set(adj[u][i]) == 1)
                        awake_neighbours++;
                }
                if (awake_neighbours >= 3)
                {
                    awakeNeighbours.pb(u);
                }
            }

            For0(i, awakeNeighbours.size())
            {
                union_set(1, awakeNeighbours[i]);
            }
            current_wake = 0;
            for (auto it : index)
            {
                if (find_set(it.second) == 1)
                {
                    current_wake++;
                }
            }
        }

        if (current_wake == n)
        {
            cout << "WAKE UP IN, " << ans - 1 << ", YEARS" << endl;
        }
        else
        {
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
        }
        // cout << current_wake << endl;
        // for (auto it : index)
        // {
        //   cout << it.first << " " << it.second << endl;
        // }
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