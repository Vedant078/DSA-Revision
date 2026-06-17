#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 
int findMax(vector<int> &arr){
    int maxSum = INT_MIN;
    int sum = 0;

    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if(sum > maxSum) maxSum = sum;
        if(sum < 0) sum = 0;
    }
    return maxSum;
}


int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(auto &it : arr){
        cin>>it;
    }

    int maximumSubarraySum = findMax(arr);
    cout<<"Maximum Subarray Sum: "<<maximumSubarraySum<<endl;
    
    return 0;
}