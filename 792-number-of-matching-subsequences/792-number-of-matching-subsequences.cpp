class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res=0;
        vector<vector<int>> v(26);
        for(int i=0;i<s.size();i++){
            char c=s[i];
            v[c-'a'].push_back(i);
        }
        for(auto word: words){
            bool found=false;
            int x=-1;
            for(auto c: word){
                auto it=upper_bound(v[c-'a'].begin(),v[c-'a'].end(),x);
                if(it==v[c-'a'].end()){
                    found=false;
                    break;
                }
                found=true;
                x=*it;
            }
            if(found==true){
                res++;
            }
        }
        return res;
    }
};