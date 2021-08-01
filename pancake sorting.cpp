//problem link:https://leetcode.com/problems/pancake-sorting/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
         
            vector<int> pancakeSorted; 
            for (int i = A.size(); i > 0; i--) 
            {
                int j = 0;
                while(A[j] != i)
                {
                    j++;
                }
                reverse(A.begin(), A.begin() + j + 1);
                pancakeSorted.push_back(j + 1);
                reverse(A.begin(), A.begin() + i); 
                pancakeSorted.push_back(i);
        }
        return pancakeSorted;
    }
};
