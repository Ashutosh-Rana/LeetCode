class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        vector<int> v;
        for(char a:s){
            v.push_back(a-'0');
        }
        priority_queue<int> pq_even,pq_odd;
        for(int a:v){
            if(a%2!=0){
                pq_odd.push(a);
            }
            else{
                pq_even.push(a);
            }
        }
        string res;
        for(int a:v){
            if(a%2!=0){
                res+=to_string(pq_odd.top());
                pq_odd.pop();
            }
            else{
                res+=to_string(pq_even.top());
                pq_even.pop();
            }
        }
        return stoi(res);
    }
};