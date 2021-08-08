//problem link:https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& a)
    {
        int n = a.size(), five = 0, ten = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 5)
            {
                five += 1;
            }
            else if(a[i] == 10)
            {
                if(five >= 1)                    
                {
                    five -= 1;
                    ten += 1;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(five > 0 && ten > 0)
                {
                    five -= 1;
                    ten -= 1;                    
                }
                else if(five > 2)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
