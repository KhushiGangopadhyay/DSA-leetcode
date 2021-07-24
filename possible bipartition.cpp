//problem link:https://leetcode.com/problems/possible-bipartition/


class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n);
        for (auto i:dislikes){
            graph[i[0]-1].push_back(i[1]-1);
            graph[i[1]-1].push_back(i[0]-1);
            
        }
        vector<int>color(n,-1);
        for (int i=0;i<n;i++){
            if (color[i]!=-1)continue;
        color[i]=0;
        queue<int>qu;
        qu.push(i);
        while(!qu.empty()){
            int cur=qu.front();
            qu.pop();
            int cur_col=color[cur];
            for (auto i: graph[cur]){
                if (cur_col==color[i])return false;
                if (color[i]!=-1)continue;
                qu.push(i);
                color[i]=1-color[cur];
            }
        }
        }
        return true;
    }
};
