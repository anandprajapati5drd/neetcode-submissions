class Solution {
public:
    int totalHours(vector<int>& piles, int hour){
        int totalHrs = 0;
        for(int i=0; i<piles.size(); i++){
            totalHrs += ceil((double)piles[i] / hour);
        }
        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            high = max(high, piles[i]);
        }
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;
            int totalHrs = totalHours(piles, mid);

            if(totalHrs <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
