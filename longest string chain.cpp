//problem link:https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    int topDown(unordered_set<string>& s,string w,unordered_map<string,int>& visited){
        if(w.size()==1){
            if(s.find(w)!=s.end())return 1;
            return 0;
        }
        int res=0;
        for(int i=0;i<w.size();i++){
            string temp = w;
            temp.erase(temp.begin()+i);
            if(s.find(temp)==s.end())continue;
            if(visited.find(temp)!=visited.end()){
                res=max(res,visited[temp]);
                continue;
            }
            int k = topDown(s,temp,visited);
            visited[temp]=k;
            res=max(res,k);
        }
        return res+1;
    }
    int longestStrChain(vector<string>& words) {
        int res=1,len=0;
        for(auto& x:words)len=max(len,(int)x.size());
        unordered_set<string> s(words.begin(),words.end());
        unordered_map<string,int> visited;
        for(auto& y:words){
            if(visited.find(y)==visited.end()){
                int k = topDown(s,y,visited);
                visited[y]=k;
                res=max(k,res);
            }
        }
        
        return res;
    }
};
