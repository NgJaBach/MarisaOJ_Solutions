#include<bits/stdc++.h>

using namespace std;

const long long INF=1e18;
const int N=200050;

vector<pair<int,int> >edge[N];
long long mincost[N];
int trace[N];

int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        edge[x].push_back({y,z});
        edge[y].push_back({x,z});
    }
    for(int i=1;i<=n;++i) mincost[i]=INF;
    priority_queue<pair<long long,int> >que;
    que.push({0,1});
    mincost[1]=0;
    trace[1]=1;
    while(!que.empty()){
        long long cost;
        int x;
        tie(cost,x)=que.top();
        que.pop();
        cost=-cost;
        if(cost!=mincost[x]) continue;
        for(auto tmp:edge[x]){
            int y,z;
            tie(y,z)=tmp;
            long long ncost=cost+z;
            if(ncost<mincost[y]){
                trace[y]=x;
                mincost[y]=ncost;
                que.push({-ncost,y});
            }
        }
    }
    if(mincost[n]==INF){
        cout<<-1;
        return 0;
    }
    cout<<mincost[n]<<endl;
    stack<int>sta;
    while(n!=trace[n]){
        sta.push(n);
        n=trace[n];
    }
    sta.push(n);
    while(!sta.empty()){
        cout<<sta.top()<<" ";
        sta.pop();
    }
    return 0;
}















