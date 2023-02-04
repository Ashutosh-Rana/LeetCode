class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // string rev_s2=string(s2.rbegin(),s2.rend());
        unordered_map<char,int> mp_s1;
        int n1=s1.length(),n2=s2.length();
        for(int i=0;i<n1;i++){
            mp_s1[s1[i]]++;
        }
        for(int i=0;i<=n2-n1;i++){
            unordered_map<char,int> mp_s2;
            for(int j=0;j<n1;j++){
                mp_s2[s2[i+j]]++;
            }
            if(mp_s1==mp_s2){
                return true;
            }
        }
        return false;
    }
};