class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> v,v2,res;
        int r=mat.size(),c=mat[0].size();
        for(int i=0;i<r;i++){
            int l=0,r=c-1,mid;
            if(mat[i][0]==0){
                v.push_back(0);
            }
            else{
                while(l<=r){
                    mid=l+(r-l)/2;
                    if(mat[i][mid]==1 && ( (mid<c-1 && mat[i][mid+1]==0) 
                                          || mid==c-1) ){
                        break;
                    }
                    if(mat[i][mid]==1){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
                v.push_back(mid+1);
            }
            
            // for(int j=0;j<c;j++){
            //     if(mat[i][j]==1){
            //         cnt++;
            //     }
            //     else{
            //         break;
            //     }
            // }
            // v.push_back(cnt);
        }
        for(int i:v){
            cout<<i<<" ";
        }
        v2=v;
        sort(v2.begin(),v2.end());
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            int ele=v2[i];
            for(int j=0;j<v.size();j++){
                if(ele==v[j] && mp[j]==0){
                    res.push_back(j);
                    mp[j]=1;
                    break;
                }
            }
        }
        return res;
    }
};