#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

vector<pair<int,int> >connect[N];
bool ok[N];

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        connect[x].push_back({y,z});
        connect[y].push_back({x,z});
    }
    for(int i=1;i<=n;++i) ok[i]=true;
    priority_queue<pair<int,int> >que; // -cost, vertex
    que.push({0,1});
    long long ans=0;
    while(!que.empty()){
        int cost,x;
        tie(cost,x)=que.top();
        que.pop();
        if(!ok[x]) continue;
        ok[x]=false;
        ans+=(-cost);
        for(auto tmp:connect[x]){
            int y,z;
            tie(y,z)=tmp;
            if(!ok[y]) continue;
            que.push({-z,y});
        }
    }
    cout<<ans;
    return 0;
}


