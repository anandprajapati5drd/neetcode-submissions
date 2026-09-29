class Solution {
public:
    void findSubsets(vector<int>& nums, vector<int>& store, vector<vector<int>> &ans, int i){
        if(i == nums.size()){
            ans.push_back({store});
            return;
        }

        store.push_back(nums[i]);
        findSubsets(nums, store, ans, i+1);

        store.pop_back();
        findSubsets(nums, store, ans, i+1);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> store;
        int idx = 0;

        findSubsets(nums, store, ans, idx);

        return ans;
    }
};
