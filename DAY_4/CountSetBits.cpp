#include<iostream>
using namespace std;

int CountBrute(unsigned int n){
    int bits = 0;
    while(n>0){
        if(n & 1){
            bits+=1;
        }
       n = n >> 1;
    }
    return bits;
}

int CountOptimised(unsigned int n){
    int bits = 0;
    while(n>0){
        bits++;
        n = n & (n-1);
    }
    return bits;
}

int main(){
    int t;
    cin>>t;
    while(t--){
         unsigned int n;
         cout<<"Enter number (decimal) :";
         cin>>n;
    
      //  int set_bits = CountBrute(n);
      int set_bits = CountOptimised(n);
        cout<<set_bits<<endl;
    }
   
    return 0;
}