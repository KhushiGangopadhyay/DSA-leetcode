//problem link:https://leetcode.com/problems/knight-probability-in-chessboard/

class Solution {
public:
  double  dp[26][26][101];
    double recur(int n,int k,int row,int column)
    {
        if(row<0||row>=n||column<0||column>=n)
        {
            return 0;
        }
        if(k==0)
        {
            return 1;
        }
        if(dp[row][column][k])
        {
            return dp[row][column][k];
        }
        double sum=0;
        sum=recur(n,k-1,row-1,column-2)+
            recur(n,k-1,row-1,column+2)+
            recur(n,k-1,row+1,column-2)+
            recur(n,k-1,row+1,column+2)+
            recur(n,k-1,row-2,column-1)+
            recur(n,k-1,row-2,column+1)+
            recur(n,k-1,row+2,column-1)+
            recur(n,k-1,row+2,column+1);
        sum/=8;
       // cout<<sum<<"\n";
        return dp[row][column][k]=sum;
    }
    double knightProbability(int n, int k, int row, int column) {
        return recur(n,k,row,column);
    }
};
