//problem link:https://leetcode.com/problems/water-bottles/


class Solution {
public:
    int numWaterBottles(int nb, int ne) {
      int drink,mt=0;
        drink=nb;
            while(nb>ne)
            {
                drink+=nb/ne;
                mt=(nb/ne)+(nb%ne);
                nb=mt;
                               
            }
        drink+=nb/ne;
        return drink;
            
    }
};
