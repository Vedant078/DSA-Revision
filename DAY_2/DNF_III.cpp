#include<iostream>
#include<vector>
using namespace std;
void DNF_2pass(vector<int>& arr){
    int l = 0;
    int n = arr.size();
    int h = arr.size()-1;
    int mid = 0;
    while(mid<=h){
        if(arr[mid]<=1){
            swap(arr[l],arr[mid]);
            l++;
            mid++;
        }
        else{
            swap(arr[mid],arr[h]);
            h--;
        }
    }
    int boundry = l;
    int l2 = 0;
    int h2 = boundry-1;
    int m = 0;
    while(m<=h2){
        if(arr[m]==0){
            swap(arr[m],arr[l2]);
            
            l2++;
            m++;
        }
        else m++;
    }
    int l3 = boundry ;
    int h3 = n-1;
    int m2 = boundry;
    while(m2<=h3){
        if(arr[m2]==2){
            swap(arr[m2],arr[l3]);
            l3++;
            m2++;
        }
        else m2++;
    }

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    DNF_2pass(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}