class Solution {
public:
    int myAtoi(string s) {
        string res;
        int flag=0;
        for(int i=0;i<s.size();i++){
            if(flag==0 && s[i]==' '){
                continue;
            }
            else if(!isdigit(s[i]) && s[i]!='-' && s[i]!='+'){
                break;
            }
            if(isdigit(s[i]) or s[i]=='-' or s[i]=='+'){
                res+=s[i];
                flag=1;
                //cout<<res<<endl;
            }
        }
        stringstream ss(res);
        int x=0;
        ss>>x;
        //cout<<x;
        return x;
    }
};