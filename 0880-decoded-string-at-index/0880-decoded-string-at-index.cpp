class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long cur_len=0;
        for(char c:s){
            if(isdigit(c)){
                cur_len*=c-'0';
            }
            else{
                cur_len++;
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(isdigit(s[i])){
                cur_len/=(s[i]-'0');
                k%=cur_len;
            }
            else{
                if(!k or k==cur_len){
                    string str(1,s[i]);
                    return str;
                }
                else{
                    cur_len--;
                }
            }
        }
        return "";
    }
};