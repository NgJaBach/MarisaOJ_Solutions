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
    rev(bend(s));
    s = '$' + s;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
    	for(int a = 0; a < 10; ++a){
    		for(int b = 0; b < 10; ++b){
    			int num = a + b;
    			if(num == (s[i] - '0'))
    				dp[i] += dp[i - 1];
    			if(i > 1 and s[i] != '0' and num == ((s[i] - '0') * 10 + (s[i - 1] - '0')))
    				dp[i] += dp[i - 2];
    		}
    	}
    }
    // for(int i = 1; i <= n; ++i)
    // 	cout << dp[i] << " ";
    cout << dp[n];
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