class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res="";
        int carry=0,max_len=max(a.size(),b.size());
        int digitA,digitB;
        for(int i=0;i<max_len;i++){
            if(i<a.size()){
                digitA=a[i]-'0';
            }
            else{
                digitA=0;
            }
            if(i<b.size()){
                digitB=b[i]-'0';
            }
            else{
                digitB=0;
            }
            int total=digitA+digitB+carry;
            res=to_string(total%2)+res;
            carry=total/2;
        }
        if(carry){
            res="1"+res;
        }
        return res;
    }
};