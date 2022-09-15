class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s.push_back(' ');
        unordered_map<char,string> mp;
        string temp;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp.push_back(s[i]);
            }
            else{
                if(mp[pattern[cnt]]!="" ){
                    if(mp[pattern[cnt]]==temp){
                        cnt++;
                        temp="";
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    for(auto j:mp){
                        if(j.second==temp){
                            return false;
                        }
                    }
                    mp[pattern[cnt]]=temp;
                    temp="";
                    cnt++;
                }
            }
        }
        if(cnt==pattern.size()){
            return true;
        }
        return false;
    }
};