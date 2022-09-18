class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size(),l=0,r=n-1,mid;
        if(letters[0]>target){
            return letters[0];
        }
        while(l<=r){
            mid=(l+r)/2;
            if(letters[mid]>target && letters[mid-1]<=target){
                return letters[mid];
            }
            if(letters[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return letters[0];
    }
};