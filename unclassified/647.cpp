// Dreaming the Impossible

#include<bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
#define pb push_back
#define pob pop_back
#define emp emplace_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define rev reverse
#define fi first
#define se second
#define gcd __gcd
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define getl(s) getline(cin, s);
#define bend(a) a.begin(),a.end()
#define mset(a) memset(a, 0, sizeof(a))
#define setpre(x) fixed << setprecision(x)
#define endl '\n'
const int N=200050,M=1000000007;
const ll INF=1e18+7;

vector<pii> connect[N];
int n, S;

namespace sub1{
    int h[205], ans, cost;
    pii par[205];
    bool mark[205];
    void dfs(int u, int p){
        h[u] = h[p] + 1;
        for(const pii &tmp: connect[u]){
            int v, w;
            tie(v, w) = tmp;
            if(v == p)
                continue;
            par[v] = {u, w};
            dfs(v, u);
        }
        return;
    }
    vector<int> dawg;
    int marking(int u, int v){
        if(h[u] < h[v])
            swap(u, v);
        while(h[u] > h[v]){
            dawg.pb(u);
            mark[u] = true;
            cost += par[u].se;
            u = par[u].fi;
        }
        while(u != v){
            mark[u] = true;
            mark[v] = true;
            dawg.pb(u);
            dawg.pb(v);
            cost += par[u].se + par[v].se;
            u = par[u].fi;
            v = par[v].fi;
        }
        dawg.pb(u);
        mark[u] = true;
        return u;
    }
    void bfs(int u, int cnt){
        ans = max(ans, cnt);
        for(const pii &tmp: connect[u]){
            int v, w;
            tie(v, w) = tmp;
            if(mark[v])
                continue;
            mark[v] = true;
            cnt += w;
            bfs(v, cnt);
        }
        return;
    }
    int solve(){
        int res = M;
        h[0] = 0;
        dfs(1, 0);
        for(int i = 1; i < n; ++i){
            for(int j = i + 1; j <= n; ++j){
                for(int c = 1; c <= n; ++c)
                    mark[c] = false;
                ans = 0; cost = 0;
                dawg.clear();
                marking(i, j);
                for(const int &tmp: dawg)
                    bfs(tmp, 0);
                // cout << i << " " << j << " : " << ans << " " << cost << endl;
                if(cost > S)
                    continue;
                res = min(ans, res);
            }
        }
        return res;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int t=1;
    while(t--){
        cin >> n >> S;
        for(int i = 1; i < n; ++i){
            int x, y, z;
            cin >> x >> y >> z;
            connect[x].pb({y, z});
            connect[y].pb({x, z});
        }
        cout<<sub1::solve()<<endl;
    }
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/