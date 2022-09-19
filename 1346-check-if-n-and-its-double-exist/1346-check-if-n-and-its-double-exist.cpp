class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                if(i!=j && arr[i]==2*arr[j]){
                    return true;
                }
            }
        }
        // unordered_set<int> s;
        // for(int i=0;i<arr.size();i++){
        //     if(s.count(2*arr[i])>0 || (arr[i]%2==0 && s.count(arr[i]/2)>0)){
        //         return true;
        //     }
        //     s.insert(arr[i]);
        // }
        return false;
    }
};