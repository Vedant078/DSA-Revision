#include<iostream>
#include<vector>
using namespace std;

int DNF(vector<int>& arr){
    int low = 0;
    int high = arr.size()-1;
    int mid = 0;
    int swap_count = 0;

    while(mid <= high){
        if(arr[mid] == 0){
            if(low != mid){
                swap(arr[low], arr[mid]);
                swap_count++;
            }
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            if(mid != high){
                swap(arr[mid], arr[high]);
                swap_count++;
            }
            high--;
        }
    }
    return swap_count;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int swaps = DNF(arr);
    cout<<"Minimum swaps required: "<<swaps<<endl;

    return 0;
}