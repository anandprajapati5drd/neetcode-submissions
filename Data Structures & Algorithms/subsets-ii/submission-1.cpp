class Solution {
   public:
    void findSubset(vector<vector<int>>& ans, vector<int>& nums,
                    vector<int>& store, int idx) {
        if (idx == nums.size()) {
            ans.push_back(store);
            return;
        }
        store.push_back(nums[idx]);
        findSubset(ans, nums, store, idx + 1);

        store.pop_back();

        while(idx + 1 < nums.size() && nums[idx] == nums[idx+1]) {
            idx++;
        }
        findSubset(ans, nums, store, idx + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int idx = 0;
        vector<int> store;

        sort(nums.begin(), nums.end());

        findSubset(ans, nums, store, idx);

        return ans;
    }
};
