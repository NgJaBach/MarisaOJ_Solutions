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

int color[N],h[N],cha[N];
vector<int>gay[N];

void dfs(int u,int p){
    h[u]=h[p]+1;
    cha[u]=p;
    for(const int &v:gay[u]) if(v!=p) dfs(v,u);
    return;
}

void painting(int x,int y,int z){
    if(h[y]<h[x]) return;
    if(color[y]) painting(x,cha[y],z);
    else{
        color[y]=z;
        painting(x,cha[y],z);
    }
    cha[y]=cha[cha[y]];
    return;
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;++i){
        int x,y;
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    dfs(1,0);
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        painting(x,y,z);
    }
    for(int i=1;i<=n;++i) cout<<color[i]<<" ";
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
9 6
1 2
1 3
3 4
3 5
2 6
2 7
2 8
7 9
6 6 2
1 1 8
1 4 9
7 9 8
2 8 4
1 9 8
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/

