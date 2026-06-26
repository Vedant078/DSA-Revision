#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<string>> groupAnag(vector<string>& s){
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> mp;

    for(auto st : s){
        string c = st;
        sort(c.begin(),c.end());

        mp[c].push_back(st);
    }

    for(auto& it : mp){
        ans.push_back(it.second);
    }
    return ans;
}


int main(){
    vector<string> s = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnag(s);
    
    for(int i = 0; i < ans.size(); i++){
        cout << "Group " << i+1 << ": [ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j];
            if(j != ans[i].size()-1) cout << ", ";
        }
        cout << " ]" << endl;
    }
    return 0;
}
