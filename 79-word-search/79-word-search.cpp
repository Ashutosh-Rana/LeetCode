class Solution {
public:
//     bool exist(vector<vector<char>>& board, string word) {
//     for (unsigned int i = 0; i < board.size(); i++) 
//         for (unsigned int j = 0; j < board[0].size(); j++) 
//             if (dfs(board, i, j, word))
//                 return true;
//     return false;
// }

// bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
//     if (!word.size())
//         return true;
//     if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
//         return false;
//     char c = board[i][j];
//     board[i][j] = '*';
//     string s = word.substr(1);
//     bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
//     board[i][j] = c;
//     return ret;
// }
    
    
    //bool res=false;
    bool recurFunction(int i,int j,vector<vector<char>>& board, string word){
        if(word.length()==0){
            return true;
        }
        
        // s+=to_string(i)+to_string(j);
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || word[0]!=board[i][j] ){
            return false;
        }
        // visited[s]=true;
        string s;
        s=word.substr(1);
        char c=board[i][j];
        board[i][j]='%';
        bool res= recurFunction(i,j+1,board,s) ||
            recurFunction(i+1,j,board,s) ||
            recurFunction(i,j-1,board,s) ||
            recurFunction(i-1,j,board,s);
        board[i][j]=c;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        //unordered_map<string,bool> visited;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                bool res=recurFunction(i,j,board,word);
                if(res){
                    return true;
                }       
            }
        }
        return false;
    }
};