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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> connect(n + 1);
    while(m--){
    	int x, y;
    	cin >> x >> y;
    	connect[x].pb(y);
    	connect[y].pb(x);
    }
    auto traverse = [&](int start){
    	vector<int> vis(n + 1, -1);
    	vis[start] = 0;
    	queue<int> que;
    	que.push(start);
    	while(!que.empty()){
    		int u = que.front();
    		que.pop();
    		for(const int &v:connect[u]){
    			if(vis[v] == -1){
    				vis[v] = vis[u] + 1;
    				que.push(v);
    			}
    		}
    	}
    	return vis;
    };
    vector<int> A = traverse(a);
    vector<int> B = traverse(b);
    int ans = M;
    for(int i = 1; i <= n; ++i){
    	if((A[i] + B[i]) % 2 == 0){
    		ans = min(ans, (A[i] + B[i]) / 2);
    	}
    }
    if(ans == M)
    	ans = -1;
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