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
struct Node{
    int x,y,cost;
};
char table[N][N];
queue<Node>que[10];
int mincost[N][N];
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,x,y,nx,ny,cost,ncost;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>table[i][j];
            mincost[i][j]=M;
        }
    }
    mincost[1][1]=0;
    que[0].push({1,1,0});
    bool ok=true;
    while(ok){
        ok=false;
        for(int i=0;i<10;++i){
            if(!que[i].empty()){
                ok=true;
                x=que[i].front().x;
                y=que[i].front().y;
                cost=que[i].front().cost;
                que[i].pop();
                if(cost==mincost[x][y]){
                    for(int j=0;j<4;++j){
                        nx=x+dx[j];
                        ny=y+dy[j];
                        if(nx<1 or ny<1 or nx>n or ny>n) continue;
                        ncost=cost+(table[nx][ny]-'0');
                        if(ncost>=mincost[nx][ny]) continue;
                        mincost[nx][ny]=ncost;
                        que[(table[nx][ny]-'0')].push({nx,ny,ncost});
                    }
                }
                break;
            }
        }
    }
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
