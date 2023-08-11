class Solution {
public:
    string reverseWords(string s) {
        vector<string> s2;
        string tmp;
        for(char c:s){
            if(c==' '){
                if(tmp!=""){
                    s2.push_back(tmp);
                }
                tmp="";
            }
            else{
                tmp+=c;
            }
        }
        if(tmp!=""){
                    s2.push_back(tmp);
                }
        reverse(s2.begin(),s2.end());
        string res;
        for(string str:s2){
            res+=str;
            res+=' ';
        }
        res.erase(res.begin()+res.size()-1);
        return res;
    }
};