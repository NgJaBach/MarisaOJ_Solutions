#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

struct edge{
    int x,y,z;
    bool operator < (const edge &other){
        return z < other.z;
    }
};

int cha[N],cha_size[N];

int find_cha(int u){
    if(cha[u]==u) return u;
    return cha[u]=find_cha(cha[u]);
}

bool Union(int x,int y){
    int u=find_cha(x);
    int v=find_cha(y);
    
    if(u==v) return false;
    
    if(cha_size[u]<cha_size[v]) swap(u,v);
    cha[v]=u;
    cha_size[u]+=cha_size[v];
    return true;
}

vector<edge>E;

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cha[i]=i;
        cha_size[i]=1;
    }
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        E.push_back({x,y,z});
    }
    sort(E.begin(),E.end());
    long long ans=0;
    for(auto tmp:E){
        int x,y,z;
        x=tmp.x;
        y=tmp.y;
        z=tmp.z;
        if(Union(x,y)) ans+=z;
    }
    cout<<ans;
    return 0;
}
/*

3 3
3 1 3
1 2 1
2 3 2


*/

