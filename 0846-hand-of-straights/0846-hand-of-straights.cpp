class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        int n=hand.size();
        unordered_map<int,int> mp;
        for(int a:hand){
            mp[a]++;
        }
        if(n%groupSize!=0){
            return false;
        }
        if(groupSize==1){
            return true;
        }
        for(int a:hand){
            if(mp[a]){
                int ele=a,flag=1;
                for(int i=0;i<groupSize;i++){
                    if(mp[ele+i]){
                        mp[ele+i]--;
                    }
                    else{
                        flag=0;
                        return false;
                    }
                }
            }
        }
        for(auto it:mp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};