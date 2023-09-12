class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        int res=0;
        sort(freq.begin(),freq.end());
        for(int i=24;i>=0;i--){
            if(!freq[i]) break;
            if(freq[i]>=freq[i+1]){
                int prev=freq[i];
                freq[i]=max(0,freq[i+1]-1);
                res+=prev-freq[i];
            }
        }
        return res;
    }
};