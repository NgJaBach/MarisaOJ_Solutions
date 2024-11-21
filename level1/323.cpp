#include<bits/stdc++.h>

using namespace std;

int n,k,ans[25];

void dequy(int pos,int base){
    if(pos>k){
        for(int i=1;i<=k;++i) cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=base;i<=n;++i){
        ans[pos]=i;
        dequy(pos+1,i+1);
    }
    return;
}

int main(){
    cin>>n>>k;
    dequy(1,1);
    return 0;
}


