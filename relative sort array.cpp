//problem link: https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> map;
        vector<int> res;
        
        
        for(auto a: arr1)
            map[a]++;
        
        
        for(auto a: arr2){
            for(int i=0; i<map[a]; i++)
                res.push_back(a);
            map.erase(a);
        }
        
        
        for(auto a: map){
            for(int i=0; i<a.second; i++)
                res.push_back(a.first);
            map.erase(a.first);
        }
        return res;
    }
};
