#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

vector<int>connect[N];

bool ok[N];

void dfs(int u){
    ok[u]=false;
    for(int v:connect[u]){
        if(ok[v]){
            dfs(v);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    
    if(m!=(n-1)){
        cout<<"NO";
        return 0;
    }
    
    while(m--){
        int x,y;
        cin>>x>>y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }
    
    for(int i=1;i<=n;++i) ok[i]=true;
    
    dfs(1);
    
    for(int i=1;i<=n;++i) if(ok[i]){
        cout<<"NO";
        return 0;
    }
    
    cout<<"YES";
    
    return 0;
}






