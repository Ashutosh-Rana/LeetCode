class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        vector<string> p;
        string temp="";
        for(int i=1;i<path.size();i++){
            if(path[i]!='/'){
                temp+=path[i];
            }
            else{
                p.push_back(temp);
                temp="";
            }
        }
        p.push_back(temp);
        for(int i=0;i<p.size();i++){
            if(!st.empty() && p[i]==".."){
                st.pop();
            }
            else if(p[i]!="" && p[i]!="." && p[i]!=".."){
                st.push(p[i]);
            }
        }
        string res="";
        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        return res.size()==0 ? "/" : res;
    }
};