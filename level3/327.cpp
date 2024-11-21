#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

vector<int>connect[N];

int cnt[N];

int dfs(int u,int p){
    cnt[u]=1;
    for(int v:connect[u]){
        if(v!=p){
            cnt[u]+=dfs(v,u);
        }
    }
    return cnt[u];
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
    dfs(1,0);
    for(int i=1;i<=n;++i) cout<<cnt[i]<<" ";
    return 0;
}


