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
    int n;
    string s;
    cin >> s;
    n = (int)s.size();
    s = "$" + s;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
    	if(s[i] == '(')
    		for(int j = 1; j <= n; ++j)
    			dp[i][j] = dp[i - 1][j - 1];
    	else if(s[i] == ')')
    		for(int j = 0; j < n; ++j)
    			dp[i][j] = dp[i - 1][j + 1];
    	else{
    		dp[i][0] = dp[i - 1][1];
    		dp[i][n] = dp[i - 1][n - 1];
    		for(int j = 1; j < n; ++j)
    			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % M;
    	}
    }
    cout << dp[n][0];
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