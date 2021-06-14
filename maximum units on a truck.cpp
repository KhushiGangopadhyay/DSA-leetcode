//problem link:https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:    
    int maximumUnits(vector<vector<int>>& box, int truck) {
        int v,k,div,count=0;
        int res=0;
        for(int i=0;i<box.size();i++)
        {
            swap(box[i][0],box[i][1]);
        }
        sort(box.begin(),box.end());
        
        for(int i=box.size()-1;i>=0;i--)
        {
            v=box[i][0];
            k=box[i][1];
          
            if(k<truck)
            {
                count+=k*v;
                truck-=k;                             
            }
            else{               
                count+=v*truck;
                break;                           
            }
        }
        return count;       
    }  
    
};
