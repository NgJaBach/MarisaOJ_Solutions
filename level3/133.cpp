#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=100005,M=1e9+7;
const ll INF=1e18+7;

int park[N],n;
bool available[N];
int find_park(int u){
    if(u==park[u]){
        if(available[u]){
            available[u]=false;
            return u;
        }
        int v=(u==n?u=1:u+1);
        return park[u]=find_park(v);
    }
    return park[u]=find_park(park[u]);
}

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;++i){
        park[i]=i;
        available[i]=true;
    }
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        cout<<find_park(x)<<" ";
    }
    return 0;
}


