class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back(to_string(nums[i]));
        }
        sort(begin(v),end(v),[](string& s1,string& s2){ 
            if(s1+s2>s2+s1){
                return true;
            }
                                                      return false;});
        string res;
        for(int i=0;i<n;i++){
            res+=v[i];
        }
        while(res[0]=='0' && res.size()>1){       //"0000"
            res.erase(res.begin());
        }
        return res;
    }
};