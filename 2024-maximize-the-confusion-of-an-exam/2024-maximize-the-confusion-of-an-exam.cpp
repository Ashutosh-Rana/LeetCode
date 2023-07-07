class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left=0,n=answerKey.size(),cnt=0,res=0;
        for(int i=0;i<n;i++){
            if(answerKey[i]=='F'){
                cnt++;
            }
            while(cnt>k){
                if(answerKey[left]=='F'){
                    cnt--;
                }
                left++;
            }
            res=max(res,i-left+1);
        }
        left=0,cnt=0;
        for(int i=0;i<n;i++){
            if(answerKey[i]=='T'){
                cnt++;
            }
            while(cnt>k){
                if(answerKey[left]=='T'){
                    cnt--;
                }
                left++;
            }
            res=max(res,i-left+1);
        }
        return res;
    }
};