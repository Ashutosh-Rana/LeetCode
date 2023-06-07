class Solution {
public:
    int minFlips(int a, int b, int c) {
        string s1,s2,s3;
        while(a){
            int rem=a%2;
            char ch=(rem+'0');
            s1=ch+s1;
            a/=2;
        }
        while(b){
            int rem=b%2;
            char ch=(rem+'0');
            s2=ch+s2;
            b/=2;
        }
        while(c){
            int rem=c%2;
            char ch=(rem+'0');
            s3=ch+s3;
            c/=2;
        }
        int max_l=max(max(s1.length(),s2.length()),s3.length());
        // int max_l=max(l,s3.length());
        for(int i=1;i<=max_l;i++){
            if(i>s1.length()){
                s1='0'+s1;
            }
            if(i>s2.length()){
                s2='0'+s2;
            }
            if(i>s3.length()){
                s3='0'+s3;
            }
        }
        cout<<s1<<" "<<s2<<' '<<s3;
        int res=0;
        for(int i=max_l-1;i>=0;i--){
            char c1=s1[i],c2=s2[i],c3=s3[i];
            if((c3=='0' && (c1=='1' && c2=='1')) ){
                res+=2;
            }
            else if( (c3=='1' && (c1=='0' && c2=='0')) or (c3=='0' && (c1=='0' && c2=='1'))                   or (c3=='0' && (c1=='1' && c2=='0')) ){
                res++;
            }
        }
        return res;
        
        
        
    }
};