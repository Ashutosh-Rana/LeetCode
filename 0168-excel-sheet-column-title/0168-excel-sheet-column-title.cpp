class Solution {
public:
    string convertToTitle(int columnNumber) {
        int a=64;
        string res="";
        while(columnNumber){
            
            int rem=columnNumber%26;
            if(!rem){
                rem=26;
            }
            char c=(a+rem);
            res=c+res;
            if(!(columnNumber%26)){
                columnNumber=(columnNumber/26)-1;
            }
            else{
                columnNumber/=26;
            }
            // cout<<rem<<" "<<columnNumber<<" "<<res<<endl;
        }
        return res;
    }
};