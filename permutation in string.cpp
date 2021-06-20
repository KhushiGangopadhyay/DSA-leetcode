//problem link:https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cur(26), res(26);
	for(char c : s1) res[c - 'a']++;
	for(int i = 0; i < s2.size(); i++) {
		cur[s2[i] - 'a']++;
		if(i >= s1.size()) cur[s2[i - s1.size()] - 'a']--;
		if(res == cur) return true;
	}
	return false;
    }
};


