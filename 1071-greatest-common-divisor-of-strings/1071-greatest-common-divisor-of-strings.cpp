class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int min_sz=min(str1.size(),str2.size());
        int max_sz=max(str1.size(),str2.size());
        int dif=max_sz-min_sz;
        for(int i=0;i<min_sz;i++){
            if(str1[i]==str2[i]){
                continue;
            }
            else{
                return "";
            }
        }
        if(dif==0){
            return str1;
        }
        int j=0;
        for(int i=min_sz;i<max_sz;i++){
            if(str1.size()>str2.size()){
                if(str1[i]==str1[j]){
                    j++;
                    continue;
                }
                else{
                    return "";
                }
            }
            else{
                if(str2[i]==str2[j]){
                    j++;
                    continue;
                }
                else{
                    return "";
                }
            }
            
        }
        int gcd=__gcd(min_sz,max_sz);
        return str1.substr(0,gcd);
    }
};