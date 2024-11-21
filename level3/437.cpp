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
    if(n == 1){
    	cout << 0;
    	return;
    }
    vector<vector<int>> connect(n + 1), vis(n + 1, vector<int>(k + 1, M));
    while(m--){
    	int x, y;
    	cin >> x >> y;
    	connect[x].pb(y);
    	connect[y].pb(x);
    }
    vis[1][k] = 1;
    queue<tuple<int,int,int>>que;
    que.push({1, k, 1}); // vertex, cooldown, steps
    while(!que.empty()){
    	int x, cd, s;
    	tie(x, cd, s) = que.front();
    	que.pop();
    	if(s != vis[x][cd]) continue;
    	if(!cd){
    		cd = k;
    		++s;
    	}
    	--cd;
    	for(const int &y:connect[x]){
    		if(vis[y][cd] > s){
    			vis[y][cd] = s;
    			que.push({y, cd, s});
    		}
    	}
    }
    cout << vis[n][0];
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