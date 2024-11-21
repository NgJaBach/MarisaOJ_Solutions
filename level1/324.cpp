#include<bits/stdc++.h>

using namespace std;

const int dx[]={1,1,2,2,-1,-1,-2,-2};
const int dy[]={2,-2,1,-1,2,-2,1,-1};
// co 8 nuoc di

int n,m;

int table[10][10];

bool back(int x,int y,int cnt){
    table[x][y]=cnt;
    if(cnt==n*m){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int i=0;i<8;++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1 and nx<=n and ny>=1 and ny<=m){
            if(table[nx][ny]==0){
                if(back(nx,ny,cnt+1)) return true;
                table[nx][ny]=0;
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    back(1,1,1);
    return 0;
}


