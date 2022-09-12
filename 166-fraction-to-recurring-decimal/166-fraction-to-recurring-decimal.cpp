// class Solution {
// public:
//     string fractionToDecimal(int numerator, int denominator) {
//         double res=numerator/double(denominator);
//         string s=to_string(res);
//         unordered_map<char,int> mp;
//         int j=s.size()-1,cnt=0;
//         while(s[j]!='.'){
//             mp[s[j]]++;
//             cnt++;
//             j--;
//         }
//         string temp="(";
//         if(mp.size()==1 ){
//             if(s[s.size()-1]=='0'){
//                 for(int i=s.size()-1;i>=0;i--){
//                     if(s[i]=='0' || s[i]=='.'){
//                         s.pop_back();
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 return s;
//             }
//             else{
//                 temp+=s[s.size()-1];
//                 temp+=")";
//                 char c=s[s.size()-1];
//                 for(int i=s.size()-1;i>=0;i--){
//                     if(s[i]==c){
//                         s.pop_back();
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 s+=temp;
//             }
//         }
//         else{
//             int flag=1;
//             for(int k=j+1;k<s.size()-mp.size();k++){
//                 if(s[k]!=s[k+mp.size()]){
//                     flag=0;
//                     break;
//                 }
//             }
//             if(!flag){
//                 if(mp[s[s.size()-1]]==1 && mp[s[s.size()-2]]==cnt-1){
//                     temp+=s[s.size()-2];
//                     temp+=")";
//                     for(int i=s.size()-1;i>=0;i--){
//                         if(s[i]!='.'){
//                             s.pop_back();
//                         }
//                         else{
//                             break;
//                         }
//                     }
//                     s+=temp;
//                     return s;
//                 }
//                 for(int i=s.size()-1;i>=0;i--){
//                     if(s[i]=='0'){
//                         s.pop_back();
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 return s;
//             }
//             else{
                
//                 for(int k=j+1;k<j+1+mp.size();k++){
//                     temp+=s[k];
//                 }
//                 temp+=")";
//                 for(int i=s.size()-1;i>=0;i--){
//                     if(s[i]!='.'){
//                         s.pop_back();
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 s+=temp;
//             }
//         }
//         return s;
//     }
// };



class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator) {
            return "0";
        }
        string ans;
        if (numerator > 0 ^ denominator > 0) {
            ans += '-';
        }
        long n = labs(numerator), d = labs(denominator), r = n % d;
        ans += to_string(n / d);
        if (!r) {
            return ans;
        }
        ans += '.';
        unordered_map<long, int> rs;
        while (r) {
            if (rs.find(r) != rs.end()) {
                ans.insert(rs[r], "(");
                ans += ')';
                break;
            }
            rs[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }
        return ans;
    }
};