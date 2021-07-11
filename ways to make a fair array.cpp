//problem link:https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
public:
    int waysToMakeFair(vector<int>& arr) {
        int n = arr.size();
        int oddsum = 0,evensum = 0,ans = 0;
        vector<int>odd(n),even(n);
        for(int i=n-1 ; i>=0 ; i--)                               
        {
            if(i&1) oddsum += arr[i];
            else evensum += arr[i];
            odd[i] = oddsum;
            even[i] = evensum;
        }
        oddsum = evensum = 0;                                       
        for(int i=0 ; i<n-1 ; i++)
        {
            if(oddsum+even[i+1] == evensum+odd[i+1]) ans++;           
            if(i&1) oddsum += arr[i];
            else evensum += arr[i];
        }
        if(oddsum == evensum) ans++;                        
        return ans;
    }
};
