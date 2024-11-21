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

int lg(const int &i) { // log2_floor
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> binlift(n + 1, vector<int>(lg(M) + 1));
    
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        binlift[i][0] = x;
    }
    
    for(int i = 1; i <= lg(M); ++i)
        for(int j = 1; j <= n; ++j)
            binlift[j][i] = binlift[binlift[j][i-1]][i-1];
    
    while(q--){
        int u, x;
        cin >> u >> x;
        for(int i = 0; i <= lg(x); ++i)
            if(x&(1<<i))
                u = binlift[u][i];

        cout << u << endl;
    }
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
3 3
2 3 1
1 1000000000
2 1000000000
3 1000000000
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/