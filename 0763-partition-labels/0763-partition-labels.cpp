class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        unordered_map<char,bool> vis;
        for(char c:s){
            mp[c]++;
        }
        int cnt=0,cnt_letters=0;
        vector<int> res;
        for(char c:s){
            if(cnt==cnt_letters && cnt!=0){
                res.push_back(cnt_letters);
                //cnt=0;
                vis[c]=true;
                cnt=mp[c];
                cnt_letters=1;
                // cout<<cnt<<endl;
                // cout<<cnt_letters<<endl;
            }
            else if(!vis[c]){
                vis[c]=true;
                cnt+=mp[c];
                //cout<<c<<" "<<cnt<<endl;
                cnt_letters++;
                //cout<<cnt_letters<<endl;
            }
            else{
                cnt_letters++;
            }
        }
        res.push_back(cnt_letters);
        return res;
    }
};