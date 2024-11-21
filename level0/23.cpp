#include<bits/stdc++.h>

using namespace std;

const int N=10005; // nen dat size mang la mot bien constant, size lon hon gioi han de bai 1 chut

int a[N]; // nen de mang o ben ngoai int main

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    int maxis,minis;
    minis=a[1]; maxis=a[1];
    for(int i=1;i<=n;++i){
        maxis=max(maxis,a[i]);
        minis=min(minis,a[i]);
    }
    cout<<maxis<<" "<<minis;
    return 0;
}


