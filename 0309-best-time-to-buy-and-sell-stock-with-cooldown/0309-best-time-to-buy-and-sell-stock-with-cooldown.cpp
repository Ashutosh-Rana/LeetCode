class Solution {
// private:
//     int dfs(int i,bool buying,map<pair<int,bool>,int> dp,vector<int>& prices){
//         if(i>=prices.size()){
//             return 0;
//         }
//         if(dp[make_pair(i,buying)]!=-1){
//             return dp[make_pair(i,buying)];
//         }
//         if(buying){
//             int buy=dfs(i+1,!buying,dp,prices)-prices[i];
//             int coolDown=dfs(i+1,buying,dp,prices);
//             dp[make_pair(i,buying)]=max(buy,coolDown);
//         }
//         else{
//             int sell=dfs(i+2,!buying,dp,prices)+prices[i];
//             int coolDown=dfs(i+1,buying,dp,prices);
//             dp[make_pair(i,buying)]=max(sell,coolDown);
//         }
//         return dp[make_pair(i,buying)];
//     }
public:
    int maxProfit(vector<int>& prices) {
        // map<pair<int,bool>,int> dp;
        // for(int i=0;i<=prices.size();i++){
        //     dp[make_pair(i,true)]=-1;
        //     dp[make_pair(i,false)]=-1;
        // }
        // return dfs(0,true,dp,prices);
        
        if(prices.size()<=1){
            return 0;
        }
        int has1_doNothing=-prices[0];
        int has0_buy=-prices[0];
        int has0_doNothing=0;
        int has1_sell=0;
        for(int i=1;i<prices.size();i++){
            has1_doNothing = has1_doNothing > has0_buy ? has1_doNothing : has0_buy;
            has0_buy = -prices[i] + has0_doNothing;
            has0_doNothing = has0_doNothing > has1_sell ? has0_doNothing : has1_sell;
            has1_sell = prices[i] + has1_doNothing;
        }
        return has1_sell > has0_doNothing ? has1_sell : has0_doNothing;
    }
};