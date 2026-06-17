#include<iostream>
#include<vector>
#include<climits>
using namespace std;
 
vector<int>  findMax(vector<int> &arr){
    vector<int> index(2,0);
    int maxSum = INT_MIN;
    int sum = 0;    
    int temp = -1;
    int start = -1;
    int end = -1;

    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if(sum > maxSum) {
            maxSum = sum;
            start = temp;
            end = i;
        }
        if(sum < 0) {
            sum = 0;
            temp = i+1;
        }
    }
    index[0] = start;
    index[1] = end;
    return index;
}


int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    vector<int> ans = findMax(arr);
    cout<<"start:"<<ans[0]<<endl;
    cout<<"end:"<<ans[1]<<endl;
    
    return 0;
}