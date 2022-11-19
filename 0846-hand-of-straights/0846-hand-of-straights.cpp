class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        int cnt=1,ele=hand[0],n=hand.size();
        unordered_map<int,bool> vis;
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
//         for(int i=1;i<n;i++){
//             if(cnt==0 && vis[i]==false){
//                 vis[i]=true;
//                 cnt++;
//                 ele=hand[i];
//             }
//             else{
//                 if(vis[i]==false && (hand[i]-ele==1)){
//                     cnt++;
//                     vis[i]=true;
//                     if(cnt==groupSize){
//                         cnt=0;
//                         i=0;
//                     }
//                     else{
//                         ele=hand[i];
//                     }
                    
//                 }
//             }
//         }
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
                // if(flag){
                //     for(int i=0;i<groupSize;i++){
                //         mp[ele+i]--;
                //     }
                // }
            }
        }
        for(auto it:mp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
        // if(cnt==0){
        //     return true;
        // }
        // return false;
    }
};