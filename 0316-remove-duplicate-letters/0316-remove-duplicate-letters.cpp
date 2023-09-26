class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp,vis;
        string res;
        for(char c:s){
            mp[c]++;
        }
        stack<char> st;
        st.push(s[0]);
        mp[s[0]]--;
        vis[s[0]]=1;
        for(int i=1;i<s.size();i++){
            if(vis[s[i]]) {
                mp[s[i]]--;
                continue;
            }
                if(s[i]<st.top()){
                    // char c=st.top();
                    while(!st.empty() && mp[st.top()]>0 && st.top()>s[i]){
                        char c=st.top();
                        st.pop();
                        // mp[c]--;
                        vis[c]=0;
                    }
                }
            if(!vis[s[i]]){
                st.push(s[i]);
                vis[s[i]]=1;
            }
            mp[s[i]]--;
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};