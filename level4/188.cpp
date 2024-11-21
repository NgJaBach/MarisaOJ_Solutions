#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=1505,M=1e9+7;
const ll INF=1e18+7;

struct node{
    int x,y,k;
};

char table[N][N];

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    vector<pair<int,int> >L;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n+1;++i){
        table[i][0]='.';
        table[i][m+1]='.';
    }
    for(int i=0;i<=m+1;++i){
        table[0][i]='.';
        table[n+1][i]='.';
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>table[i][j];
            if(table[i][j]=='L') L.push_back({i,j});
        }
    }
    pair<int,int>A,B;
    A=L.front(); B=L.back();
    queue<node>que;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(table[i][j]!='X') continue;
            if(table[i-1][j]!='X' or table[i+1][j]!='X' or table[i][j-1]!='X' or table[i][j+1]!='X') que.push({i,j,1});
        }
    }
    int mark=0;
    while(!que.empty()){
        
    }
    return 0;
}


