#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,tong=0;
    cin>>n;
    n=abs(n); // dua n ve nguyen duong
    while(n>0){
        tong+=n%10;
        n/=10;
    }
    cout<<tong;
    return 0;
}


