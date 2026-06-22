#include<iostream>
#include<vector>
using namespace std;

int findMini(vector<int>& arr){
    int l = 0;
    int h  = arr.size()-1;
    while(l<h){
        int mid = l+(h-l)/2;

       if(arr[mid] > arr[h] ){
        l= mid+1;
       }
       else h = mid;
    }
    return arr[l];
}



int main(){
    int n;
    cout<<"Enter size of vector: ";
    cin>>n;

    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    

    int found_mini = findMini(arr);
    cout<<found_mini<<endl;

    return 0;
}