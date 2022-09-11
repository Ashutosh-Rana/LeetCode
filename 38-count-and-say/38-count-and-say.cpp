class Solution {
private:
    string recurFunction(int i,int n,string s){
        if(i==n){
            return s;
        }
        // if(i==1){
        //     s= "1";
        // }
        string temp;
        int cnt=1;
        for(int j=0;j<s.size()-1;j++){
            if(s[j]==s[j+1]){
                cnt++;
            }
            else{
                temp+=to_string(cnt);
                temp+=s[j];
                cnt=1;
            }
        }
        temp+=to_string(cnt);
        temp+=s[s.size()-1];
        //cout<<temp<<endl;
        s=temp;
        return recurFunction(i+1,n,s);
    }
public:
    string countAndSay(int n) {
        string res=recurFunction(1,n,"1");
        return res;
    }
};