class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = 0;

        int leftMax = nums[l];
        int rightMax = nums[r];

        while(l < r){
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax, nums[l]);
                ans += leftMax - nums[l];
            }else{
                r--;
                rightMax = max(rightMax, nums[r]);
                ans += rightMax - nums[r];
            }
        }
        return ans;
    }
};
