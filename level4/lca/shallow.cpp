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
int cha[N][D],subsize[N],h[N];
vector<int>gay[N];
void dfs(int u,int p){
    h[u]=h[p]+1;
    cha[u][0]=p;
    for(int i=1;i<D;++i) cha[u][i]=cha[cha[u][i-1]][i-1];
    subsize[u]=1;
    for(auto v:gay[u]){
        if(v==p) continue;
        dfs(v,u);
        subsize[u]+=subsize[v];
    }
    return;
}
int lca(int u,int v){
    if(h[u]<h[v]) swap(u,v);
    int k=h[u]-h[v];
    for(int i=0;i<D;++i) if((k>>i)&1) u=cha[u][i];
    if(u==v) return u;
    for(int i=D-1;i>=0;--i) if(cha[u][i]!=cha[v][i]){
        u=cha[u][i];
        v=cha[v][i];
    }
    return cha[u][0];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int n,q,k,x,y,z,a,b,c;
    cin>>n>>q;
    for(int i=1;i<n;++i){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    dfs(1,1);
    while(q--){
        cin>>k;
        cin>>a>>b; c=lca(a,b);
        k-=2;
        while(k--){
//            cout<<"--> "<<a<<" "<<b<<" "<<c<<endl;
            cin>>x; y=c;
            z=lca(x,y);
            if(z==c) continue;
            c=z; a=x;
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
8 7
1 2
2 3
1 4
2 5
4 6
5 7
7 8
5 4 5 2 2 6 
3 2 2 3 
6 6 2 5 3 2 2 
3 4 3 3 
5 6 3 8 7 2 
4 2 1 8 5 
2 5 2 

10 1
1 2
1 3
2 4
2 5
4 6
2 7
2 8
6 9
2 10
4 2 8 1 4
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

