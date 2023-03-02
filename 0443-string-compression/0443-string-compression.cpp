class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt=0,temp=1,j=0,n=chars.size();
        // cout<<chars[1]<<endl;
        for(int i=1;i<chars.size();i++){
            // cout<<i<<" "<<temp<<endl;
            if(chars[i]==chars[i-1]){
                temp++;
            }
            else{
                if(temp==1){
                    chars[j]=chars[i-1];
                    j++;
                    cnt++;
                }
                else if(temp>=10){
                    string s=to_string(temp);
                    cnt+=s.size()+1;
                    int sz=s.size();
                    chars[j]=chars[i-1];
                    for(int k=1;k<=s.size();k++){
                        chars[j+k]=s[k-1];
                    }
                    j+=sz+1;
                    // chars[j+1]=cnt;
                    
                }
                else{
                    chars[j]=chars[i-1];
                    chars[j+1]=temp+'0';
                    cnt+=2;
                    j+=2;
                }
                // cnt++;
                temp=1;
            }
            // cout<<j<<" "<<chars[j]<<endl;
        }
        // cout<<chars.size()<<endl;
        if(temp==1){
            chars[j]=chars[n-1];
                    cnt++;
                }
                else if(temp>=10){
                    string s=to_string(temp);
                    cnt+=s.size()+1;
                    int sz=s.size();
                    chars[j]=chars[n-1];
                    for(int k=1;k<=s.size();k++){
                        chars[j+k]=s[k-1];
                    }
                }
                else{
                    cnt+=2;
                    chars[j]=chars[n-1];
                    chars[j+1]=temp+'0';
                    // cnt+=2;
                }
        return cnt;
    }
};