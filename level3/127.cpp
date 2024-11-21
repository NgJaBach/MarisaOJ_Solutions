#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

vector<int>connect[N];

int maxis,pick;

void dfs(int u,int p,int cnt){
    if(cnt>maxis){
        maxis=cnt;
        pick=u;
    }
    for(int v:connect[u]){
        if(v!=p){
            dfs(v,u,cnt+1);
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
    
    maxis=0; pick=1;
    dfs(1,0,0);
    
    int A=pick;
    
    maxis=0; pick=A;
    dfs(A,0,0);
    
    int B=pick;
    
    cout<<maxis;
    return 0;
}


