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
const int N=200050,M=1000000007;
const ll INF=1e18+7;
int a[N],arr[N];
int cha[N][25],subsize[N],h[N];
vector<int>gay[N];
void dfs(int u,int p){
    h[u]=h[p]+1;
    subsize[u]=1;
    cha[u][0]=p;
    for(int i=1;i<25;++i) cha[u][i]=cha[cha[u][i-1]][i-1];
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
    for(int i=0;i<25;++i){
        if((k>>i)&1){
            u=cha[u][i];
        }
    }
    if(u==v) return u;
    for(int i=24;i>=0;--i){
        if(cha[u][i]!=cha[v][i]){
            u=cha[u][i];
            v=cha[v][i];
        }
    }
    return cha[u][0];
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
int pos,val;
void Update(int x,int L,int R){
    if(L==R){
        seg[x]=val;
        return;
    }
    int mid=(L+R)/2;
    if(pos>mid) Update(2*x+1,mid+1,R);
    else Update(2*x,L,mid);
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
int nChain,nBase,chainHead[N],chainID[N],posBase[N];
void HLD(int u){
    if(chainHead[nChain]==0) chainHead[nChain]=u;
    chainID[u]=nChain;
    arr[nBase]=a[u];
    posBase[u]=nBase++;
    int spe=-1;
    for(auto v:gay[u]){
        if(v==cha[u][0]) continue;
        if((spe==-1) or (subsize[spe]<subsize[v])) spe=v;
    }
    if(spe!=-1) HLD(spe);
    for(auto v:gay[u]){
        if((v!=cha[u][0]) and (v!=spe)){
            ++nChain;
            HLD(v);
        }
    }
    return;
}
int n;
int Setup_Query(int x,int y){
    if(x>y) swap(x,y);
//    cout<<"==> "<<x<<" "<<y<<endl;
    lo=x; hi=y;
    return Query(1,1,n);
}
int HLD_Query(int u,int v){
    int uchain=chainID[u];
    int vchain=chainID[v];
    int ans=-1;
    while(true){
        if(uchain==vchain){
            ans=max(ans,Setup_Query(posBase[u],posBase[v]));
            break;
        }
        ans=max(ans,Setup_Query(posBase[u],posBase[chainHead[uchain]]));
        u=cha[chainHead[uchain]][0];
        uchain=chainID[u];
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
//    freopen(".inp","r",stdin);
//    freopen(".out","w",stdout);
    int x,y,z,q,t;
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<n;++i){
        cin>>x>>y;
        gay[x].pb(y);
        gay[y].pb(x);
    }
    h[0]=0; nChain=1; nBase=1;
    dfs(1,0);
    HLD(1);
//    for(int i=1;i<=n;++i) cout<<arr[i]<<' '; cout<<endl;
//    for(int i=1;i<=n;++i) cout<<chainHead[i]<<" "; cout<<endl;
//    for(int i=1;i<=n;++i) cout<<posBase[i]<<" "; cout<<endl;
    Build(1,1,n);
    while(q--){
        cin>>t>>x>>y;
        if(t==1){
            pos=posBase[x]; val=y;
            Update(1,1,n);
        }
        else{
            z=lca(x,y);
//            cout<<"--> "<<z<<endl;
            cout<<max(HLD_Query(x,z),HLD_Query(y,z))<<endl;
        }
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

