#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

vector<int>connect[N];

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;
    
    if(n==1){
        cout<<1;
        return 0;
    }
    else if(n==2){
        cout<<1;
        return 0;
    }
    
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
    
    int cnt=0;
    
    for(int i=1;i<=n;++i) if((int)connect[i].size()==1) ++cnt;
    
    cout<<cnt;
    
    return 0;
}


