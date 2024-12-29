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
    cin >> n;
    int a[n + 1][n + 1], dp[n + 1][n + 1][n + 1][n + 1];
    for(int i = 0; i <= n; ++i)
    	for(int j = 0; j <= n; ++j)
    		for(int x = 0; x <= n; ++x)
    			for(int y = 0; y <= n; ++y)
    				dp[i][j][x][y] = 0;
    for(int i = 1; i <= n; ++i)
    	for(int j = 1; j <= n; ++j)
    		cin >> a[i][j];
    for(int i = 1; i <= n; ++i){
    	for(int j = 1; j <= n; ++j){
    		for(int x = 1; x <= n; ++x){
    			for(int y = 1; y <= n; ++y){
    				dp[i][j][x][y] = max(max(dp[i - 1][j][x - 1][y], dp[i][j - 1][x - 1][y]), max(dp[i - 1][j][x][y - 1], dp[i][j - 1][x][y - 1]));
    				if((i + j) != (x + y))
    					continue;
    				if(i == x and j == y)
    					dp[i][j][x][y] += a[i][j];
    				else
    					dp[i][j][x][y] += a[i][j] + a[x][y];
    				// cout << "(" << i << "," << j << ") (" << x << "," << y << ") : " << dp[i][j][x][y] << endl;
    			}
    		}
    	}
    }
    cout << dp[n][n][n][n];
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