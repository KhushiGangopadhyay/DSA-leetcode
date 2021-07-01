//problem link:https://leetcode.com/problems/keys-and-rooms/


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> dfs; 
        dfs.push(0);
        unordered_set<int> vis = {0};
        
        while (!dfs.empty()) {
            int i = dfs.top(); 
            dfs.pop();
            
            for (int j : rooms[i])
                if (vis.count(j) == 0) {
                    dfs.push(j);
                    vis.insert(j);
                    if (rooms.size() == vis.size()) return true;
                }
        }
        return rooms.size() == vis.size();
    }
};
