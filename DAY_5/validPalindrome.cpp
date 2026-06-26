#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        //converting s to continous small letter string
        for(int i=0;i<s.length();i++){
                if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                    temp += s[i];
                }
                else if(s[i]>='A' && s[i]<='Z'){
                    temp += (char)(s[i]+32);
                }
                else continue;
        }
       
        int l = 0;
        int h = temp.length()-1;
        cout<<"clean :"<<temp<<endl;
        cout<<"length:"<<temp.length()<<endl;
        while(l<=h){
            if(temp[l] != temp[h] ){
                return false;
            }
            else{
                l+=1;
                h-=1;
            }
        }
        return true;
    }
};

int main(){
    string st;
    cout<<"Enter a string for check :";
    getline(cin,st);

    Solution s;
   cout<<s.isPalindrome(st)<<endl;
    return 0;
}