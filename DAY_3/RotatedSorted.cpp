#include<iostream>
#include<vector>
using namespace std;

int findRotated(vector<int>& arr, int target){
    int l = 0;
    int h = arr.size()-1;
    while(l<=h){
        int mid = l+(h-l)/2;

        if(arr[mid] == target) return mid;

        if(arr[l]<=arr[mid]){
            if(arr[l]<= target && target < arr[mid]){
                h = mid - 1;
            }
            else l = mid+1;
        }
        else {
            if(arr[mid] < target && target <= arr[h]){
                l = mid+1;
            }
            else h = mid-1;
        }
    }
    return -1;
}



int main(){
    int n;
    cout<<"Enter size of vector: ";
    cin>>n;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x = 0;
    cout<<"Enter target :";
    cin>>x;

    int found_index = findRotated(arr, x);

    if(found_index == -1){
        cout<<"Error 404! Element not found"<<endl;
    }
    else cout<<found_index<<endl;

    return 0;
}