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

struct node{
	int Left, Right, cnt;
};

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    node nah = {0, 0, M};
    vector<vector<node>> dp(n + 1, vector<node>(n + 1, nah));
    for(int i = 1; i <= n; ++i){
    	cin >> a[i];
    	dp[i][i] = {a[i], a[i], 1};
    }
    for(int k = 2; k <= n; ++k){
    	for(int i = k; i <= n; ++i){
    		int x = i - k + 1;
    		int y = i;
    		for(int j = x; j < y; ++j){
    			if(dp[x][j].Right == dp[j + 1][y].Left){
    				int ncnt = dp[x][j].cnt + dp[j + 1][y].cnt - 1;
    				int Left, Right;

    				if(dp[x][j].cnt == 1)
    					Left = dp[x][j].Right + 1;
    				else
    					Left = dp[x][j].Left;

    				if(dp[j + 1][y].cnt == 1)
    					Right = dp[j + 1][y].Left + 1;
    				else
    					Right = dp[j + 1][y].Right;

    				if(ncnt < dp[x][y].cnt)
    					dp[x][y] = {Left, Right, ncnt};
    			}
    			else{
    				int ncnt = dp[x][j].cnt + dp[j + 1][y].cnt;
    				if(ncnt < dp[x][y].cnt)
    					dp[x][y] = {dp[x][j].Left, dp[j + 1][y].Right, ncnt};
    			}
    		}
    	}
    }
    // for(int i = 1; i <= n; ++i){
    // 	for(int j = i; j <= n; ++j){
    // 		cout << dp[i][j].cnt << " ";
    // 	}
    // 	cout << endl;
    // }
    cout << dp[1][n].cnt;
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