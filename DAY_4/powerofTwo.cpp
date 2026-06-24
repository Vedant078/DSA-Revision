#include<iostream>
using namespace std;
bool isPowerOf2(int n){
    long x = n;
    if(x==0)return false;
    if(x & (x-1))return false;
    else return true;
}

int main(){
    int n;
    cout<<"Enter the value of (n):";
    cin>>n;

    bool ans = isPowerOf2(n);
    cout<<ans<<endl;
}