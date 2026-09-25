class Solution {
public:
    set<vector<int>> s;
    void combination(int target, int idx, vector<int> &combi, vector<int> &nums, vector<vector<int>> &ans){
        if(idx == nums.size() || target < 0) return;

        if(target == 0){
            if(s.find(combi) == s.end()){
            ans.push_back({combi});
            s.insert(combi);
            return;
            }
        }

        combi.push_back(nums[idx]);
        combination(target-nums[idx], idx+1, combi, nums, ans);
        combination(target-nums[idx], idx, combi, nums, ans);

        combi.pop_back();
        combination(target, idx+1, combi, nums, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combi;

        combination(target, 0, combi, nums, ans);

        return ans;

    }
};
