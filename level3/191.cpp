#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const int lim=18;
const ll INF=1e18+7;

int h[N],par[N][lim];
vector<int>connect[N];

void dfs(int u,int p){
    h[u]=h[p]+1;
    par[u][0]=p;
    for(int i=1;i<lim;++i) par[u][i]=par[ par[u][i-1] ][i-1];
    for(int v:connect[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    return;
}

int lca(int u,int v){
    if(h[u]<h[v]) swap(u,v);
    int k=h[u]-h[v];
    for(int i=0;i<lim;++i) if((k>>i)&1) u=par[u][i];
    if(u==v) return u;
    for(int i=lim-1;i>=0;--i){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;++i){
        int x,y;
        cin>>x>>y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }
    dfs(1,0);
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<" ";
    }
    return 0;
}

/*
7 3
1 2
1 3
2 4
2 5
3 6
3 7

4 5
4 6
2 7

*/
