#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

vector<int>connect[N];

int h[N];

void dfs(int u,int p){
    h[u]=h[p]+1;
    for(int v:connect[u]){
        if(v!=p){
            dfs(v,u);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;
    
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
    h[0]=0;
    dfs(1,0);
    for(int i=1;i<=n;++i) cout<<h[i]-1<<" ";
    return 0;
}


