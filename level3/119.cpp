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
const int N=1050,M=1000000007;
const ll INF=1e18+7;

char table[N][N];
int visit[N][N];
int n,m;

bool valid(int x,int y){
	if(x<1 or y<1 or x>n or y>m) return false;
	if(visit[x][y]!=M) return false;
	return (table[x][y]!='1');
}
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=m;++j){
    		cin>>table[i][j];
    		visit[i][j]=M;
		}
	}
	queue<pii>que;
	visit[1][1]=0;
	que.push({1,1});
	while(!que.empty()){
		int x,y;
		tie(x,y)=que.front();
		que.pop();
		for(int i=0;i<4;++i){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(valid(nx,ny)){
				visit[nx][ny]=visit[x][y]+1;
				que.push({nx,ny});
			}
		}
	}
	cout<<visit[n][m];
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

