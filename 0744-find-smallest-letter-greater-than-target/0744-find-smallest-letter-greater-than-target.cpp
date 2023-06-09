class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // int i=target-'a';
        // cout<<i;
        int n=letters.size();
        if(target-'a'>=letters[n-1]-'a'){
            return letters[0];
        }
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(letters[mid]-'a' > target-'a' ){
                r=mid;
            }
            else if(letters[mid]-'a' <= target-'a'){
                l=mid+1;
            }
        }
        // if(l>=letters.size()-1 && target){
        //     return letters[0];
        // }
        return letters[l];
    }
};