#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

const int N=200005,M=1e9+7;
const ll INF=1e18+7;

map<int,int>cnt;

int main(){
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    cin>>s;
    int tong=0;
    ll ans=0;
    ++cnt[0];
    for(int i=0;i<(int)s.size();++i){
        if(s[i]=='0') --tong;
        else ++tong;
        ans+=cnt[tong];
        ++cnt[tong];
    }
    cout<<ans;
    return 0;
}


