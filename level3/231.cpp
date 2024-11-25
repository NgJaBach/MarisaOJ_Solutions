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
const int N=100050,M=1000000007;
const ll INF=1e18+7;

ll dp[N][105], ans;
int n, k;
vector<int>connect[N];

void dfs(int u, int p){
	dp[u][1] = 1;
	vector<ll>sum(k + 1, 0);
	for(const int &v: connect[u]){
		if(v == p)
			continue;
		dfs(v, u);
		ans += dp[v][k];
		for(int i = 1; i < k; ++i){
			dp[u][i + 1] += dp[v][i];
			ans += dp[v][i] * sum[k - i];
		}
		for(int i = 1; i < k; ++i)
			sum[i] += dp[v][i];
	}
	return;
}

void solve(){
    cin >> n >> k;
    if(k == 1){
    	cout << n;
    	return;
    }
    for(int i = 1; i <= n; ++i)
    	for(int j = 1; j <= k; ++j)
    		dp[i][j] = 0;
    for(int i = 1; i < n; ++i){
    	int x, y;
    	cin >> x >> y;
    	connect[x].pb(y);
    	connect[y].pb(x);
    }
    ans = 0;
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