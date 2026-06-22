#include<iostream>
#include<vector>
using namespace std;

int first(vector<int>& arr, int target){
    int l = 0;
    int h = arr.size()-1;
    int ans = -1;
    while(l<=h){
        int mid = l+(h-l)/2;
        
        if(arr[mid] == target){
            ans = mid;
            h = mid - 1;
        }
        else if(arr[mid]< target)l = mid+1;
        else h = mid-1;
    }
    return ans;
}

int last(vector<int>& arr, int target){
    int l = 0;
    int h = arr.size()-1;
    int ans = -1;
    while(l<=h){
        int mid = l+(h-l)/2;
        
        if(arr[mid] == target){
            ans = mid;
            l = mid + 1;
        }
        else if(arr[mid]< target)l = mid+1;
        else h = mid-1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the target: ";
    cin>>x;
    int firstOcc = first(arr,x);
    int lastOcc = last(arr,x);

    cout<<"["<<firstOcc<<","<<lastOcc<<"]";

    return 0;

}