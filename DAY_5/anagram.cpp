#include<iostream>
#include<string>
using namespace std;

bool isAnagram(string &s1, string &s2){
    if(s1.length()!=s2.length())return false;
    int arr[26];
    for(int i=0;i<25;i++)arr[i]=0;

    for(int i=0;i<s1.length();i++){
        arr[s1[i]-'a']++;
        arr[s2[i]-'a']--;
    }

    for(int i=0;i<25;i++){
        if(arr[i]==1)return false;
    }
    return true;
}

int main(){
    string s1,s2;
    cout<<"Enter s1 : ";
    cin>>s1;

    cout<<"Enter s2 :";
    cin>>s2;

    cout<<isAnagram(s1,s2);
    return 0;
}