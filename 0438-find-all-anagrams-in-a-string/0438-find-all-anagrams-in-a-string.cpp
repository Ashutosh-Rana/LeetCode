class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<int,int> mp_p,mp_s;
        int len_s=s.length(),len_p=p.length();
        vector<int> res;
        for(int i=0;i<26;i++){
            mp_p[i]=0;
            mp_s[i]=0;
        }
        for(int i=0;i<len_p;i++){
            mp_p[p[i]-'a']++;
            mp_s[s[i]-'a']++;
        }
        // for(int i=0;i<len_s;i++){
        //     mp_s[s[i]]++;
        // }
        if(mp_p==mp_s){
            res.push_back(0);
        }
        //int before=0;
        //cout<<mp_s.size()<<endl;
        for(int i=len_p;i<len_s;i++){
            mp_s[s[i]-'a']++;
            mp_s[s[i-len_p]-'a']--;
            // cout<<s[i]<<" "<<mp_s[s[i]]<<"  "<<s[i-1]<<" "<<mp_s[s[i-1]]<<"  "<<s[i-2]<<" "<<mp_s[s[i-2]]<<" "<<mp_s.size()<<"\n";
            if(mp_s==mp_p){
                res.push_back(i-len_p+1);
            }
        }
        return res;
    }
};