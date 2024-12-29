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

void solve(){
    string s;
    cin >> s;
    int n = (int)s.size();
    s = '$' + s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, M));
    for(int i = 1; i <= n; ++i)
    	dp[i][i] = 1;
    for(int i = 2; i <= n; ++i){
    	if((s[i - 1] == '(' and s[i] == ')') or (s[i - 1] == '[' and s[i] == ']'))
    		dp[i - 1][i] = 0;
    	else
    		dp[i - 1][i] = 2;
    }
    for(int k = 3; k <= n; ++k){
    	for(int i = k; i <= n; ++i){
    		int x = i - k + 1;
    		int y = i;
    		if((s[x] == '(' and s[y] == ')') or (s[x] == '[' and s[y] == ']'))
    			dp[x][y] = min(dp[x][y], dp[x + 1][y - 1]);
    		else
    			dp[x][y] = min(dp[x][y], dp[x + 1][y - 1] + 2);
    		for(int j = x; j < y; ++j)
    			dp[x][y] = min(dp[x][y], dp[x][j] + dp[j + 1][y]);
    	}
    }
    // for(int i = 1; i <= n; ++i){
    // 	for(int j = i; j <= n; ++j){
    // 		cout << dp[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    cout << dp[1][n];
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