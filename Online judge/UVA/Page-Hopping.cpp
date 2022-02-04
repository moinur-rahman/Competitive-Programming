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
#define cs 200005
#define pi acos(-1)
#define INF (int)INFINITY

void in()
{
#ifndef ONllNE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
vector<int> adj[105];
int visited[105];
int level[105];

void bfs(int s, int n)
{
    queue<int> Q;
    Q.push(s);

    visited[s] = 1;
    level[s] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < adj[u].size(); i++)
            if (visited[adj[u][i]] == 0)
            {
                int v = adj[u][i];
                visited[v] = 1;
                level[v] = level[u] + 1;
                Q.push(v);
            }
    }
}

void solve()
{
    int a, b, q = 0;
    cin >> a >> b;

    while (a && b)
    {
        q++;
        memset(adj, 0, sizeof adj);
        int n = 0;
        set<int> s;
        while (a && b)
        {
            adj[a].pb(b);
            n++;
            s.insert(a);
            s.insert(b);
            cin >> a >> b;
        }
        int ans = 0, cnt = 0;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            memset(level, 0, sizeof level);
            memset(visited, 0, sizeof visited);
            bfs((*it), n);
            for (auto bit = s.begin(); bit != s.end(); bit++)
            {
                if ((*it) == (*bit))
                    continue;
                if (!visited[(*bit)])
                    continue;
                cnt++;
                ans += level[(*bit)];
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n", q, (ans * 1.0 / cnt));
        cin >> a >> b;
    }
}

int main()
{
    in();
    int t = 1;
    // cin >> t;
    For1(i, t)
    {
        // cout << "Case " << i << ": ";
        solve();
    }
}
