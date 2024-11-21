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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>dolls, vis(n + 1, M);
    vector<vector<int>>connect(n + 1);
    while(k--){
    	int x;
    	cin >> x;
    	dolls.pb(x);
    }
    while(m--){
    	int x, y;
    	cin >> x >> y;
    	connect[x].pb(y);
    	connect[y].pb(x);
    }
    queue<pii>que;
    que.push({n, 0});
    vis[n] = 0;
    while(!que.empty()){
    	int x, d;
    	tie(x, d) = que.front();
    	que.pop();
    	++d;
    	for(const int &y:connect[x]){
    		if(vis[y] > d){
    			vis[y] = d;
    			que.push({y, d});
    		}
    	}
    }
    int ans = 0;
    for(const int &x:dolls){
    	if(vis[x] <= vis[1]){
    		++ans;
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