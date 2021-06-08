//problem link:https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return "";
        int start = 0, end = 0;
        for(int i=0; i<s.length(); i++) {
            int len = max(helper(s, i, i), helper(s, i, i+1));
            if(len > (end-start)) {
                start = i - ((len-1)/2);
                end = i + (len/2);
            }
        }
        return s.substr(start, end-start+1);
    }
    
    int helper(string s, int left, int right) {
        if(s.length()==0 || left>right) return 0;
        while(left>=0 && right<s.length() && s[left]==s[right]) left--, right++;
        return right-left-1;
    }
};
