#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int LongestSubs(string s){
    vector<int> hash(256,-1);
    int n = s.length();
    int r = 0;
    int l = 0;
    int maxLen = INT_MIN;
    while(r<n){
        if(hash[s[r]]!=-1){
            l = max(hash[s[r]]+1, l);
        }

        maxLen = max(maxLen,r-l+1);
        hash[s[r]] = r;
        r++;
    }

    return maxLen;
}


int main(){
    string s = "raceacar";
    cout<<LongestSubs(s)<<endl;
    return 0;
}