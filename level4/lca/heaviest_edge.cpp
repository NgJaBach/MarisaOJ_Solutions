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
const int N=100050,M=1000000007,D=20;
const ll INF=1e18+7;
int a[N],arr[N],cha[N][D],h[N],subsize[N];
vector<pair<int,int> >gay[N];
void dfs(int u,int p){
    h[u]=h[p]+1;
    subsize[u]=1;
    cha[u][0]=p;
    for(int i=1;i<D;++i) cha[u][i]=cha[cha[u][i-1]][i-1];
    for(auto v:gay[u]){
        if(v.fi==p) continue;
        a[v.fi]=v.se;
        dfs(v.fi,u);
        subsize[u]+=subsize[v.fi];
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
int nBase,posBase[N],chainHead[N];
void HLD(int u,int p){
    chainHead[u]=p;
    arr[nBase]=a[u];
    posBase[u]=nBase++;
    int spe=-1;
    for(auto v:gay[u]){
        if(v.fi==cha[u][0]) continue;
        if((spe==-1) or (subsize[spe]<subsize[v.fi])) spe=v.fi;
    }
    if(spe!=-1) HLD(spe,p);
    for(auto v:gay[u]){
        if((v.fi==spe) or (v.fi==cha[u][0])) continue;
        HLD(v.fi,v.fi);
    }
    return;
}
int seg[4*N];
void Build(int x,int L,int R){
    if(L==R){
        seg[x]=arr[L];
        return;
    }
    int mid=(L+R)/2;
    Build(2*x,L,mid);
    Build(2*x+1,mid+1,R);
    seg[x]=max(seg[2*x],seg[2*x+1]);
    return;
}
int lo,hi;
int Query(int x,int L,int R){
    if(L>hi or R<lo) return 0;
    if(L>=lo and R<=hi) return seg[x];
    int mid=(L+R)/2;
    return max(Query(2*x,L,mid),Query(2*x+1,mid+1,R));
}
int n;
int Path(int x,int anc){
    int ans=0;
    int k=h[x]-h[anc];
    if(k==0) return 0;
    --k;
    int y=x;
    for(int i=0;i<D;++i) if((k>>i)&1) x=cha[x][i];
    while(true){
        if(h[chainHead[y]]<=h[x]){
            lo=posBase[x]; hi=posBase[y];
            ans=max(ans,Query(1,1,n));
            break;
        }
        else{
            lo=posBase[chainHead[y]]; hi=posBase[y];
            ans=max(ans,Query(1,1,n));
            y=cha[chainHead[y]][0];
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int q,x,y,z;
    cin>>n>>q;
    for(int i=1;i<n;++i){
        cin>>x>>y>>z;
        gay[x].pb({y,z});
        gay[y].pb({x,z});
    }
    dfs(1,1);
    nBase=1;
    HLD(1,1);
    Build(1,1,n);
//    for(int i=1;i<=n;++i) cout<<a[i]<<" "; cout<<endl;
    while(q--){
        cin>>x>>y;
        z=lca(x,y);
        cout<<max(Path(x,z),Path(y,z))<<" ";
    }
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
8 4
1 3 7
3 5 1
2 5 2
5 6 10
6 8 8
7 8 2
4 8 3
5 4
1 2
1 5
1 7
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
10
7
7
10
------------------------------    |
==================================+
*/

