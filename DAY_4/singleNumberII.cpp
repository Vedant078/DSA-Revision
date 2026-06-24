#include<iostream>
#include<vector>
using namespace std;
class Solution{
public: 
    int singleNumber(vector<int>& arr){
        int ans = 0;
        for(int bits = 0; bits<31;bits++){
            int cnt = 0;
            for(int i=0;i<arr.size();i++){
                if(arr[i] & (1LL<<bits)){
                    cnt++;
                }
            }
            if(cnt%3==1){
                ans = ans | (1LL<<bits);
            }
        }
        return ans;
    }
};

int main(){

    vector<int> arr = {2,2,2,3,3,4};
    Solution s;
    cout<<s.singleNumber(arr);

    return 0;
}