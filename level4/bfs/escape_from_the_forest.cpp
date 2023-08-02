// NgJaBach: Forever Meadow <3

#include<bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define bend(a) a.begin(),a.end()
#define rev(x) reverse(bend(x))
#define mset(a) memset(a, 0, sizeof(a))
#define fi first
#define se second
#define gcd __gcd
#define getl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
#define endl '\n'
const int N=5050,M=1000000007;
const ll INF=1e18+7;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
char table[N][N];
struct Node{
    int x,y,cost,dir;
};
deque<Node>que;
int mincost[N][N];
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,x,y,cost,dir,nx,ny,ncost;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>table[i][j];
            mincost[i][j]=M;
        }
    }
    que.pb({1,1,0,2});
    mincost[1][1]=0;
    while(!que.empty()){
        x=que.front().x;
        y=que.front().y;
        cost=que.front().cost;
        dir=que.front().dir;
        que.pop_front();
        if(cost!=mincost[x][y]) continue;
        for(int i=0;i<4;++i){
            nx=x+dx[i];
            ny=y+dy[i];
            if(nx<1 or nx>n or ny<1 or ny>n) continue;
            if(table[nx][ny]=='#') continue;
            ncost=cost;
            if(i!=dir) ++ncost;
            if(ncost>=mincost[nx][ny]) continue;
            mincost[nx][ny]=ncost;
            if(i!=dir) que.pb({nx,ny,ncost,i});
            else que.push_front({nx,ny,ncost,i});
        }
    }
    if(mincost[n][n]==M) mincost[n][n]=-1;
    cout<<mincost[n][n];
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

