#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if(a==0 && b==0){
        cout<<"INFINITE SOLUTIONS";
        return 0;
    }
    if(a==0 || (-b)%a!=0){
        cout<<"NO SOLUTION";
        return 0;
    }
    cout<<(-b)/a;
    return 0;
}

