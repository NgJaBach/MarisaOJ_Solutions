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
    if(n == 1){
    	cout << 1;
    	return;
    }
    s = '$' + s;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[1][1] = 1;
    for(int i = 2; i <= n; ++i){
        dp[i][1] = dp[i - 1][2] + 1;
        if(s[i - 1] != s[i])
            dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
        dp[i][2] = dp[i - 2][1] + 1;
        if(i < 4)
            continue;
        if(s[i - 3] == s[i - 1] and s[i - 2] == s[i])
            dp[i][2] = max(dp[i][2], dp[i - 2][2] + 1);
    }
    cout << max(dp[n][1], dp[n][2]);
    return;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int t=1;
    cin >> t;
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
4
abc
aabbb
aaaaaa
pppqqppppq
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/