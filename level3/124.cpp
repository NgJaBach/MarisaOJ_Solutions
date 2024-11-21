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

double dist(const pld &A, const pld &B){
	double x = A.fi - B.fi;
	double y = A.se - B.se;
	return sqrt(x*x + y*y);
}

bool check(const vector<vector<int>> &connect, const int &n){
	vector<bool> vis(n + 1, false);
	vis[1] = true;
	queue<int> que;
	que.push(1);
	int cnt = n - 1;
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(const int &y:connect[x]){
			if(vis[y]) continue;
			vis[y] = true;
			--cnt;
			que.push(y);
		}
	}
	return cnt == 0;
}

void solve(){
    int n;
    cin >> n;
    vector<pld> coords;
    for(int i = 0; i < n; ++i){
    	int x, y;
    	cin >> x >> y;
    	coords.pb({x, y});
    }
    double L = 0, R = M, mid;
    const double eps = 0.00000001;
    while((R - L) > eps){
    	vector<vector<int>> connect(n + 1);
    	mid = (L + R) / 2;
    	// cout << setpre(6) << L << " " << R << " : " << mid << endl;
    	for(int i = 1; i <= n; ++i)
    		for(int j = 1; j < i; ++j)
    			if(!(dist(coords[i - 1], coords[j - 1]) > mid * 2)){
    				connect[i].pb(j);
    				connect[j].pb(i);
    			}
    	if(check(connect, n))
    		R = mid;
    	else
    		L = mid;
    }
    cout << setpre(6) << R;
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