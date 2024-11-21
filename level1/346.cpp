#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll k,a[25];

bool dequy(int pos,ll sum){
    if(sum==k) return true;
    else if(pos>n or sum>k) return false;
    
    if(dequy(pos+1,sum)==true) return true;
    if(dequy(pos+1,sum+a[pos])==true) return true;
    
    return false;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    
    if(dequy(1,0)==true) cout<<"YES";
    else cout<<"NO";
    return 0;
}


