class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        //long long res=0;
        // unordered_map<string,int> mp;
        int n=ideas.size();
        // for(int i=0;i<n;i++){
        //     mp[ideas[i]]=1;
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         string s1=ideas[i],s2=ideas[j];
        //         // cout<<s1<<" "<<s2<<endl;
        //         swap(s1[0],s2[0]);
        //         // cout<<s1<<" "<<s2<<endl;
        //         // cout<<mp[s1]<<" "<<mp[s2]<<endl;
        //         if(!mp[s1] && !mp[s2]){
        //             res++;
        //         }
        //     }
        // }
        // return res*2;
        vector<unordered_set<string>> suffix(26);
        for(int i=0;i<n;i++){
            suffix[ideas[i][0]-'a'].insert(ideas[i].substr(1));
        }
        long long res=0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                auto setA=suffix[i];
                auto setB=suffix[j];
                int intersect=0;
                for(auto item:setA){
                    intersect+=setB.count(item);
                }
                res+=2*(setA.size()-intersect)*(setB.size()-intersect);
            }
        }
        return res;
    }
};