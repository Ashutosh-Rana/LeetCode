class Solution {
public:
    string reverseVowels(string s) {
        string t;int cnt =-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                t.push_back(s[i]);
                cnt++;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i]=t[cnt];
                // cout<<t[cnt]<<endl;
                // cout<<cnt<<endl;
                cnt--;
            }
        }
        return s;
    }
};