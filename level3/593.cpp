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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connect(n + 1);
    while(m--){
    	int x, y;
    	cin >> x >> y;
    	connect[x].pb(y);
    	connect[y].pb(x);
    }
    int q;
    cin >> q;
    stack<tuple<int, int, int>>sta;
    while(q--){
    	int x, d, c;
    	cin >> x >> d >> c;
    	sta.push({x, d, c});
    }
    vector<int> color(n + 1, 0);
    vector<vector<bool>> vis(n + 1, vector<bool>(11, false));
    while(!sta.empty()){
    	int x, d, c;
    	tie(x, d, c) = sta.top();
    	sta.pop();
    	if(vis[x][d]) continue;
    	queue<pii>que;
    	que.push({x, d});
    	vis[x][d] = true;
    	while(!que.empty()){
    		tie(x, d) = que.front();
    		que.pop();
    		// cout << "--> " << x << " " << d << " " << c << endl;
    		if(!color[x])
    			color[x] = c;
    		if(!d) continue;
    		--d;
    		for(const int &y:connect[x]){
    			if(vis[y][d]) continue;
    			vis[y][d] = true;
    			que.push({y, d});
    		}
    	}
    }
    for(int i = 1; i <= n; ++i)
    	cout << color[i] << endl;
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