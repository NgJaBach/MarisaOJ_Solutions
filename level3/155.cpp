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
const int N=200050,M=123456789;
const ll INF=1e18+7;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[0][i] = 1;
    }
    for(int i = 1; i <= k; ++i){
        vector<int>last(N, -1);
        for(int j = i; j <= n; ++j){
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % M;
            if(last[a[j]] != -1)
                dp[i][j] = (dp[i][j] - dp[i - 1][last[a[j]] - 1] + M) % M;
            last[a[j]] = j;
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << dp[k][n];
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