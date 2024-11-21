#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

int cha[N],cha_size[N];

int find_cha(int u){
    if(cha[u]==u) return u;
    return cha[u]=find_cha(cha[u]);
}

void Union(int x,int y){
    int u=find_cha(x);
    int v=find_cha(y);
    
    if(u==v) return;
    
    if(cha_size[u]<cha_size[v]) swap(u,v);
    cha[v]=u;
    cha_size[u]+=cha_size[v];
    return;
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cha[i]=i;
        cha_size[i]=1;
    }
    while(m--){
        int t,u,v;
        cin>>t>>u>>v;
        if(t==1) Union(u,v);
        else{
            u=find_cha(u);
            v=find_cha(v);
            if(u==v) cout<<"YES";
            else cout<<"NO";
            cout<<endl;
        }
    }
    return 0;
}
