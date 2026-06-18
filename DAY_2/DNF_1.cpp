#include<iostream>
#include<vector>
using namespace std;

void DNF(vector<int>& arr){
    int l = 0;
    int h = arr.size()-1;
    int mid = 0;

    while(mid<=h){
        if(arr[mid]==0){
            swap(arr[l],arr[mid]);
            l++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[h]);
            h--;
        }
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    DNF(arr);

    cout<<"array after sorting:"<<endl;
   
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}