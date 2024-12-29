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

vector<int> connect[N];
ll a[N], dp[N], ans;

void dfs(int u, int p){
	dp[u] = a[u];
	ll maxfi = -INF, maxse = -INF;
	for(const int &v: connect[u]){
		if(v == p)
			continue;
		dfs(v, u);
		
		if(dp[v] > maxfi){
			maxse = maxfi;
			maxfi = dp[v];
		}
		else
			maxse = max(maxse, dp[v]);

		dp[u] = max(dp[u], dp[v] + a[u]);
	}
	ans = max(ans, max(dp[u], a[u] + maxfi + maxse));
	return;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    	cin >> a[i];
    for(int i = 1; i < n; ++i){
    	int x, y;
    	cin >> x >> y;
    	connect[x].pb(y);
    	connect[y].pb(x);
    }
    ans = -INF;
    dfs(1, 1);
    cout << ans;
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int t=1;
    while(t--){
        solve();
        cout<<endl;
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