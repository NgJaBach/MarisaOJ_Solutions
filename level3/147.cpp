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
const ll INF=1e15+7;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(2, vector<ll>(k + 1, -INF)));
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        for(int j = 0; j <= k; ++j){
            dp[i%2][false][j] = a + max(dp[1 - i%2][false][j], dp[1 - i%2][true][j]);
            dp[i%2][true][j] = max(dp[1 - i%2][true][j], j ? dp[1 - i%2][false][j - 1] : -INF);
        }
    }
    ll ans = -INF;
    for(int i = 0; i <= k; ++i)
        ans = max({ans, dp[n%2][false][i], dp[n%2][true][i]});
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