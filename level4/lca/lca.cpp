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
const int N=200050,M=1000000007,D=20;
const ll INF=1e18+7;
vector<int>gay[N];
int cha[N][D],h[N];
void dfs(int u,int p){
    h[u]=h[p]+1;
    cha[u][0]=p;
    for(int i=1;i<D;++i) cha[u][i]=cha[cha[u][i-1]][i-1];
    for(auto v:gay[u]) if(v!=p) dfs(v,u);
    return;
}
int lca(int u,int v){
    if(h[u]<h[v]) swap(u,v);
    int k=h[u]-h[v];
    for(int i=0;i<D;++i) if((k>>i)&1) u=cha[u][i];
    if(u==v) return u;
    for(int i=D-1;i>=0;--i){
        if(cha[u][i]!=cha[v][i]){
            u=cha[u][i];
            v=cha[v][i];
        }
    }
    return cha[u][0];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,q,x,y;
    cin>>n>>q;
    for(int i=1;i<n;++i){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    h[0]=0;
    dfs(1,0);
    while(q--){
        cin>>x>>y;
        cout<<lca(x,y)<<" ";
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

