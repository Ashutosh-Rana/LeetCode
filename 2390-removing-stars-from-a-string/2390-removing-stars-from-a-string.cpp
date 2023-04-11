class Solution {
public:
    string removeStars(string s) {
        string res="";
        vector<char> v;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                v.push_back(s[i]);
            }
            else{
                v.pop_back();
                // st.push(s[i]);
            }
        }
        for(char c:v){
            // char top_ele=st.top();
            res+=c;
            // st.pop();
        }
        // int cnt=0;
        // for(int i=0;i<s.size()-1;i++){
        //     cnt++;
        // }
        return res;
    }
};