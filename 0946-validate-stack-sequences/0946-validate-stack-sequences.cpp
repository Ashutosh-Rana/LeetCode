class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st1,st2;
        int n=pushed.size();
        for(int i=n-1;i>=0;i--){
            st2.push(popped[i]);
        }
        for(int i=0;i<n;i++){
            st1.push(pushed[i]);
            while(!st1.empty() && st1.top()==st2.top()){
                st1.pop();
                st2.pop();
            }
        }
        return st1.empty() ? true:false;
    }
};