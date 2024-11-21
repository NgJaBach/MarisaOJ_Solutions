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
    vector<vector<char>> table(n + 1, vector<char>(m + 1));
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    for(int i = 1; i <= n; ++i){
    	for(int j = 1; j <= m; ++j){
    		cin >> table[i][j];
    	}
    }
    int white, empty;
    const int dx[] = {0,0,1,-1};
    const int dy[] = {1,-1,0,0};
    auto check = [&](int x, int y){
    	return (x > 0 and x <= n) and (y > 0 and y <= m);
    };
    function<void(int,int)> traverse = [&](int x, int y){
    	if(table[x][y] == '.')
    		++empty;
    	else
    		++white;
    	for(int i = 0; i < 4; ++i){
    		int nx = x + dx[i];
    		int ny = y + dy[i];
    		if(!check(nx, ny)) continue;
    		if(table[nx][ny] == 'B') continue;
    		if(vis[nx][ny]) continue;
    		vis[nx][ny] = true;
    		traverse(nx, ny);
    	}
    };
    int ans = 0;
    for(int i = 1; i <= n; ++i){
    	for(int j = 1; j <= m; ++j){
    		if(table[i][j] == 'B') continue;
    		if(vis[i][j]) continue;
    		white = 0; empty = 0;
    		vis[i][j] = true;
    		traverse(i, j);
    		if(empty) continue;
    		// cout << "--> " << i << " " << j << " : " << white << endl;
    		ans += white;
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