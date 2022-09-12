class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator){
            return "0";
        }
        string ans;
        if((numerator<0 and denominator>0) or (numerator>0 and denominator<0)){
            ans+="-";
        }
        long n=abs(numerator),d=abs(denominator);
        ans+=to_string(n/d);
        long r=n%d;
        if(!r){
            return ans;
        }
        ans+=".";
        unordered_map<long,int> mp;
        
        while(r){
            if(mp.find(r)!=mp.end()){
                ans.insert(mp[r],"(");
                ans+=")";
                break;
            }
            mp[r]=ans.size();
            r*=10;
            ans+=to_string(r/d);
            r%=d;
        }
        return ans;
    }
};