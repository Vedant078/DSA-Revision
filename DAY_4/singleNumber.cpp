#include<iostream>
using namespace std;

int singleInt(int arr[], int n){
    int number = arr[0];

    for(int i=1;i<n;i++){
        number ^= arr[i];
    }
    return number;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter size of array: ";
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int ans = singleInt(arr,n);
        cout<<"Number Appearing for only one time :"<<ans<<endl;
    }
    return 0;
}