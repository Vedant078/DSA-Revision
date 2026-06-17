#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int kadane_min(vector<int> &arr){
    int minSum = INT_MAX;
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];

        if(sum<minSum){
            minSum = sum;
        }
        if(sum>0){
            sum = 0;
        }
    }
    return minSum;
}

int totalSum(vector<int>& arr){
    int s = 0;
    for(int i=0;i<arr.size();i++){
        s+=arr[i];
    }
    return s;
}

int kadane_max(vector<int> &arr){
    int maxSum = INT_MIN;
    int sum = 0;

    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if(sum > maxSum) maxSum = sum;
        if(sum < 0) sum = 0;
    }
    return maxSum;
}

int circularMax(vector<int> &arr){
    int maxSum = kadane_max(arr);
    if(maxSum<0)return maxSum;
    int total_sum = totalSum(arr);
    int minSum = kadane_min(arr);
    int wrapped = total_sum - minSum;
    return max(maxSum,wrapped);
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(auto &it : arr){
        cin>>it;
    }

    int maximumSubarraySum = circularMax(arr);
    cout<<"Maximum Subarray Sum: "<<maximumSubarraySum<<endl;
    
    return 0;
}