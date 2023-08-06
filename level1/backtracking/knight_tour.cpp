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
const int N=10,M=1000000007;
const ll INF=1e18+7;
int table[N][N],n,m;
void tableclear(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            table[i][j]=0;
        }
    }
    return;
}
void tableout(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
const int dx[]={1,1,-1,-1,2,2,-2,-2};
const int dy[]={2,-2,2,-2,1,-1,1,-1};
void dfs(int x,int y,int k){
    if(k==n*m){
        tableout();
        exit(0);
    }
    ++k;
    int nx,ny;
    for(int i=0;i<8;++i){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<1 or ny<1 or nx>n or ny>m) continue;
        if(table[nx][ny]) continue;
        table[nx][ny]=k;
        dfs(nx,ny,k);
        table[nx][ny]=0;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    cin>>n>>m;
    
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

