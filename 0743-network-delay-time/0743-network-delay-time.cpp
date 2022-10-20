class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int k) {
        vector<int> dist(N+1,INT_MAX);
        dist[k]=0;
        for(int i=0;i<N-1;i++){
            for(vector<int> edge : times){
                int u=edge[0],v=edge[1],w=edge[2];
                if(u!=INT_MAX && (unsigned)dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        int delay=0;
        for(int i=1;i<=N;i++){
            delay=max(delay,dist[i]);
        }
        if(delay==INT_MAX){
            return -1;
        }
        return delay;
    }
};