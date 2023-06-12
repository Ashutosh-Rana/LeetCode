class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> res;
        if(!n){
            return res;
        }
        // char c=nums[0]+'0';
        string s=to_string(nums[0]);
        // cout<<c;
        // s+=c;
        for(int i=1;i<n;i++){
            if(nums[i]==1+nums[i-1]){
                if(s.size()>1 && s[s.size()-1]=='>'){
                    continue;
                }
                else{
                    s+="->";
                }
            }
            else{
                if(s.size()>1 && s[s.size()-1]=='>'){
                    // char c1=nums[i-1]+'0';
                    s+=to_string(nums[i-1]);
                    res.push_back(s);
                }
                else{
                    res.push_back(s);
                }
                // char c2=nums[i]+'0';
                // s="";
                s=to_string(nums[i]);
            }
        }
        if(s.size()>1 && s[s.size()-1]=='>'){
            // char c3=nums[n-1]+'0';
            s+=to_string(nums[n-1]);
        }
        res.push_back(s);
        return res;
    }
};