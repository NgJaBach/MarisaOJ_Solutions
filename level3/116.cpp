// The Shadow Monarch

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

int reach[N];
vector<int>gay[N];

void solve(){
    int n,m;
    cin>>n>>m;
    while(m--){
    	int x,y;
    	cin>>x>>y;
    	gay[x].pb(y);
    	gay[y].pb(x);
	}
	for(int i=1;i<=n;++i) reach[i]=-1;
	reach[1]=0;
	queue<int>que;
	que.push(1);
	while(!que.empty()){
		int x=que.front();
		que.pop();
		for(int y:gay[x]){
			if(reach[y]!=-1) continue;
			reach[y]=reach[x]+1;
			que.push(y);
		}
	}
	for(int i=2;i<=n;++i) cout<<reach[i]<<" ";
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

