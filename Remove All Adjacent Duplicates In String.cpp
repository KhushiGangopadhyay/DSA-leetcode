problem link:https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
          string res = "";
         for(const char &v: s) {
           if(v == res.back()) {
             res.pop_back();
           } else {
             res.push_back(v);
           }
        }
        
        return res;
    }
};
