class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++) 
        for (unsigned int j = 0; j < board[0].size(); j++) 
            if (dfs(board, i, j, word))
                return true;
    return false;
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
    board[i][j] = c;
    return ret;
}
    
    
    //bool res=false;
//     bool recurFunction(int cnt,int i,int j,vector<vector<char>>& board, string word,unordered_map<string,bool> visited){
//         if(cnt==word.length()){
//             return true;
//         }
//         string s;
//         s+=to_string(i)+to_string(j);
//         if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || word[cnt]!=board[i][j] || visited[s]==true){
//             return false;
//         }
//         visited[s]=true;
//         bool res= recurFunction(cnt+1,i,j+1,board,word,visited) ||
//             recurFunction(cnt+1,i+1,j,board,word,visited) ||
//             recurFunction(cnt+1,i,j-1,board,word,visited) ||
//             recurFunction(cnt+1,i-1,j,board,word,visited);
//         visited[s]=false;
//         return res;
//     }
    
//     bool exist(vector<vector<char>>& board, string word) {
//         unordered_map<string,bool> visited;
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 bool res=recurFunction(0,i,j,board,word,visited);
//                 if(res){
//                     return true;
//                 }       
//             }
//         }
//         return false;
//     }
};