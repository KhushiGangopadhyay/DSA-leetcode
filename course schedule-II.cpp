//problem link:https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
   
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n,vector<int>());
        queue<int> q;
        vector<int> in_degree(n,0);
        vector<int> ans;
        
        for(auto p: prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++in_degree[p[0]];
        }
        
        for(int i=0;i<n;++i) {
            if(in_degree[i]==0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int child: graph[cur]) {
                --in_degree[child];
                if(in_degree[child]==0) {
                    q.push(child);
                }
            }
        }
        return ans.size() == n ? ans : vector<int>();
    }
};
