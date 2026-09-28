class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;

        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }

        int ans = 0;

        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int count = 1;
                int curr = it;

                while(st.find(curr+1) != st.end()){
                    count++;
                    curr = curr+1;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
