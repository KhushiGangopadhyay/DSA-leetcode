//problem link:https://leetcode.com/problems/is-graph-bipartite/


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1); 
        for(int i = 0; i<n;i++){
            if(color[i] ==  -1){ 
                queue<int> frontier; 
                frontier.push(i);
                color[i] = 0;  
                while(frontier.empty() ==  false){
                    int s = frontier.front(); 
                    frontier.pop();
                    for(auto it : graph[s]){
                        if(color[it] ==  -1){ 
                            frontier.push(it);
                            color[it] = (color[s]+1)%2; 
                        }else if(color[it] == color[s]){ 
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
