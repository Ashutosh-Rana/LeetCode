class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0,sz=flowerbed.size();
        if(n==0){
            return true;
        }
        if(sz==1 ){
            if(n<=1 && flowerbed[0]==0){
                return true;
            }
            else{
                return false;
            }
        }
        for(int i=0;i<sz;i++){
            cout<<i<<" "<<sz<<endl;
            if(i==0 or i==sz-1){
                if(i==0 && flowerbed[i]==0 && i+1<sz && flowerbed[i+1]==0){
                    cnt++;
                    flowerbed[i]=1;
                }
                else if(i==sz-1 && flowerbed[i]==0 && i-1>0 && flowerbed[i-1]==0){
                    cnt++;
                    flowerbed[i]=1;
                }
            }
            else{
                if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    cnt++;
                    flowerbed[i]=1;
                }
            }
        }
        return cnt>=n ? true:false;
    }
};