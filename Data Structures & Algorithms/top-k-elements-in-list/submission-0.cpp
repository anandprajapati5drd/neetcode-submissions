class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> answer;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto &i : mp){
            pq.push({i.second, i.first});
        }

        while(k){
            answer.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return answer;
    }
};
