class Solution {
private:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int cnt=0;
        vector<int> pair=pairs[0];
        for(int i=0;i<pairs.size();i++){
            if(i==0 || pairs[i][0]>pair[1]){
                cnt++;
                pair=pairs[i];
            }
        }
        return cnt;
    }
};