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
    int n, k;
    cin >> n >> k;
    vector<pii> items;
    while(n--){
    	int w, v, a;
    	cin >> w >> v >> a;
    	for(int i = 0; i < 32; ++i){
    		int num = (1 << i);
    		if(a <= num)
    			break;
    		items.pb({w * num, v * num});
    		a -= num;
    	}
    	items.pb({w * a, v * a});
    }
    vector<ll> dp(k + 1, -1);
    dp[0] = 0;
    for(const pii &tmp: items){
    	int w, v;
    	tie(w, v) = tmp;
    	for(int i = k; i >= w; --i){
    		if(dp[i - w] == -1)
    			continue;
    		dp[i] = max(dp[i], dp[i - w] + v);
    	}
    }
    ll ans = 0;
    for(int i = 1; i <= k; ++i)
    	ans = max(ans, dp[i]);
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