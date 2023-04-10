class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            // cout<<s[i]<<" "<<st.size()<<endl;
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else if( st.size()!=0 && ((s[i]==')' and st.top()=='(') or (s[i]=='}' and st.top()=='{') or (s[i]==']' and st.top()=='[')) ){
                // cout<<s[i]<<' '<<st.size()<<endl;
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty() ? true : false;
    }
};