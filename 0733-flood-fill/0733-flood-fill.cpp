class Solution {
private:
    void bfs(vector<vector<int>>& image,vector<vector<int>>& vis, int sr, int sc, int color){
        int r=image.size(),c=image[0].size(),initCol=image[sr][sc];
        vis[sr][sc]=1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int newR=q.front().first;
            int newC=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(newR+i>=0 && newR+i<r && newC+j>=0 && newC+j<c &&
                       !vis[newR+i][newC+j] && abs(i)!=abs(j) && 
                       image[newR+i][newC+j]==initCol){
                        q.push({newR+i,newC+j});
                        image[newR+i][newC+j]=color;
                        vis[newR+i][newC+j]=1;
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        int r=image.size(),c=image[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        bfs(image,vis,sr,sc,color);
        return image;
    }
};