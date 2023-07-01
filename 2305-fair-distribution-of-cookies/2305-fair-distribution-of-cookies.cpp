class Solution {
    int res=INT_MAX;
    void solve(vector<int>& cookies,vector<int> &v, int k,int start){
        int n=cookies.size();
        if(start==n){
            int maxm=INT_MIN;
            for(int i=0;i<k;i++){
                maxm=max(maxm,v[i]);
            }
            res=min(res,maxm);
            return;
        }
        for(int i=0;i<k;i++){
            v[i]+=cookies[start];
            solve(cookies,v,k,start+1);
            v[i]-=cookies[start];
            if(!v[i]){
                break;
            }
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int> v(n,0);
        solve(cookies,v,k,0);
        return res;
    }
};