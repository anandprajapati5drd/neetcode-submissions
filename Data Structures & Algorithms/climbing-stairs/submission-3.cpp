class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        int firstPrev = 2;
        int secPrev = 1;

        for(int i=3; i<=n; i++){
            int curr = firstPrev + secPrev;
            secPrev = firstPrev;
            firstPrev = curr;
        }
        return firstPrev;
    }
};
