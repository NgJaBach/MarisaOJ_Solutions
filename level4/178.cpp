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
#define mt make_tuple
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
const int N=150,M=1000000007;
const ll INF=1e18+7;

const int dx[]={1,-1,0,0,0,0};
const int dy[]={0,0,1,-1,0,0};
const int dz[]={0,0,0,0,1,-1};


int a[N][N][N],n;
ll mincost[N][N][N];

bool valid(const int &x,const int &y,const int &z){
    if(x<1 or y<1 or z<1 or x>n or y>n or z>n) return false;
    return true;
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                cin>>a[i][j][k];
                mincost[i][j][k]=INF;
            }
        }
    }
    priority_queue<tuple<ll,int,int,int> >que;
    ll cost,ncost;
    int x,y,z,nx,ny,nz;
    mincost[1][1][1]=0;
    que.push(mt(0,1,1,1));
    while(!que.empty()){
        tie(cost,x,y,z)=que.top();
        que.pop();
        cost=-cost;
        if(cost!=mincost[x][y][z]) continue;
        for(int i=0;i<6;++i){
            tie(nx,ny,nz)=mt(x+dx[i],y+dy[i],z+dz[i]);
            if(!valid(nx,ny,nz)) continue;
            ncost=cost+a[nx][ny][nz];
            if(ncost<mincost[nx][ny][nz]){
                mincost[nx][ny][nz]=ncost;
                que.push(mt(-ncost,nx,ny,nz));
            }
        }
    }
    cout<<mincost[n][n][n];
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

