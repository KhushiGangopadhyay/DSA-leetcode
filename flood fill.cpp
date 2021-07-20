//problem link:https://leetcode.com/problems/flood-fill/

class Solution 
{
public:
    void helper(vector<vector<int>>&image,int row,int col,int newColor,int prev)
    {
        if(row<0 || col<0 || row>=image.size() || col>=image[0].size() || image[row][col]!=prev)
        {
            return;
        }
        image[row][col]=newColor;
       // cout<<row<<"\t"<<col<<"\n";
        helper(image,row-1,col,newColor,prev);
        helper(image,row,col-1,newColor,prev);
        helper(image,row+1,col,newColor,prev);
        helper(image,row,col+1,newColor,prev);
    }
    vector<vector<int>> floodFill(vector<vector<int>>&image,int sr,int sc,int newColor) 
    {
        if(newColor==image[sr][sc])
        {
            return image;
        }
        helper(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};
