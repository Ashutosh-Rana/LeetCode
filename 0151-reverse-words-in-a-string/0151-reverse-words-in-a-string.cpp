class Solution {
public:
    string reverseWords(string s) {
        
        string tmp,res;
        for(char c:s){
            if(c==' '){
                if(tmp!=""){
                    tmp+=" ";
                    res=tmp+res;
                }
                tmp="";
            }
            else{
                tmp+=c;
            }
        }
        if(tmp!=""){
            tmp+=" ";
            res=tmp+res;
        }
        res.erase(res.begin()+res.size()-1);
        return res;
    }
};