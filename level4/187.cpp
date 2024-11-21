#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=100005,M=1e9+7;
const ll INF=1e18+7;

ll mincost[55][N];
vector<pair<int,int> >gay[N];
vector<int>starting[55];

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j){
            mincost[i][j]=INF;
        }
    }
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        starting[x].push_back(i);
    }
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        gay[x].push_back({y,z});
        gay[y].push_back({x,z});
    }
    for(int i=1;i<=k;++i){
        priority_queue<pair<ll,int> >que;
        for(const int &x:starting[i]){
            que.push({0,x});
            mincost[i][x]=0;
        }
        while(!que.empty()){
            int x;
            ll cost;
            tie(cost,x)=que.top();
            que.pop();
            cost=-cost;
            if(cost!=mincost[i][x]) continue;
            for(auto tmp:gay[x]){
                ll ncost=cost+tmp.second;
                int y=tmp.first;
                if(mincost[i][y]>ncost){
                    mincost[i][y]=ncost;
                    que.push({-ncost,y});
                }
            }
        }
    }
    int ans;
    ll best=INF;
    for(int i=1;i<=n;++i){
        ll sum=0;
        bool ok=true;
        for(int j=1;j<=k;++j){
            if(mincost[j][i]==INF){
                ok=false;
                break;
            }
            sum+=mincost[j][i];
        }
        if(!ok) continue;
        if(sum<best){
            best=sum;
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}


