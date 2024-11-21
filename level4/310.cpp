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

struct SparseTable{
    int n;
    vector<vector<int>>table;
    
    int lg(const unsigned long long &i) { // log2_floor
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
    
    SparseTable(const vector<int>&arr){
        n = (int)arr.size();

        table.resize(lg(n) + 1, vector<int>(n));
        for(int i = 0; i < n; ++i)
            table[0][i] = arr[i];
        for(int i = 1; i <= lg(n); ++i)
            for(int j = 0; j + (1 << i) <= n; ++j)
                table[i][j] = gcd(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
    }

    int RMQ(const int &L, const int &R){ // 0-based indexing
        int i = lg(R - L + 1);
        return gcd(table[i][L], table[i][R - (1 << i) + 1]);
    }
};

void solve(){
    int n;
    vector<int>arr;
    cin >> n;
    for(int i = 0; i < n; ++i){
    	int x;
    	cin >> x;
    	arr.pb(x);
    }
    SparseTable sp(arr);
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
    	int last = i;
    	while(last <= n){
    		ll cur = sp.RMQ(i - 1, last - 1);
    		int L = last, R = n, pos = i;
    		while(L <= R){
    			int mid = (L + R) / 2;
    			if(sp.RMQ(i - 1, mid - 1) != cur)
    				R = mid - 1;
    			else{
    				L = mid + 1;
    				pos = mid;
    			}
    		}
    		ans = (ans + cur * (pos - last + 1)) % M;
    		last = pos + 1;
    	}
    }
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