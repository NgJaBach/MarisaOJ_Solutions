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
const int N=500000,M=1000000007;
const ll INF=1e18+7;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> dp(2, vector<int>(2 * N + 1, -M));
    dp[0][N] = 0;
    while(n--){
    	int x, y;
    	cin >> x >> y;
    	for(int i = 0; i <= 2 * N; ++i){
    		dp[1][i] = dp[0][i];
    		int idx = i - x;
    		if(idx < 0 or idx > 2 * N)
    			continue;
    		if(dp[0][idx] == -M)
    			continue;
    		dp[1][i] = max(dp[1][i], dp[0][idx] + (x + y));
    	}
    	swap(dp[0], dp[1]);
    }
    int ans = 0;	
    for(int i = 0; i <= N * 2; ++i){
    	if(dp[0][i] == -M)
    		continue;
    	int x = i - N;
    	int y = dp[0][i] - x;
    	// cout << x << " -> " << y << " : " << dp[0][i] << endl;
    	// continue;
    	if(y < 0)
    		continue;
    	ans = max(ans, dp[0][i]);
    }
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