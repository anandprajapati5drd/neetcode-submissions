class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0;
        int ans = 0;
        int curr = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]-1 == curr){
                count++;
                curr = nums[i];
            }else if(curr != nums[i]){
                count = 1;
                curr = nums[i];
            }
            ans = max(count, ans);
        }
        return ans;
    }
};
