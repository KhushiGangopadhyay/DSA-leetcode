//problem link:https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/



class Solution {
public:
    int countGoodSubstrings(string s) {
        int count=0; string temp="";
        
        
        for(int i=0; i<3 ; i++){
            temp += s[i];
        }
        
        if(temp[0]!=temp[1] && temp[1]!=temp[2] && temp[0]!=temp[2]) count++;
        
        
        for(int i=3; i<s.size() ; i++){
            temp += s[i];
           
            temp.erase(temp.begin());

            if(temp[0]!=temp[1] && temp[1]!=temp[2] && temp[0]!=temp[2]) {
                count++;
            }
        }
        return count;
    }
};
