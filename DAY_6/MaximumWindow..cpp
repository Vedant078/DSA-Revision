#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaximumWindowSum(vector<int>& arr, int k){
    int sum = 0;
    int maxi = INT_MIN;

    for(int i = 0; i < k; i++) sum += arr[i];
    maxi = sum;

    for(int r = k; r < arr.size(); r++){
        sum += arr[r];
        sum -= arr[r - k];
        maxi = max(sum, maxi);
    }
    return maxi;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    cout<<"Enter array: ";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<MaximumWindowSum(arr,k)<<endl;

    return 0;
}