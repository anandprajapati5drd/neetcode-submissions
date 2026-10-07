class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, n);
        vector<int> left(n, -1);

        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = INT_MIN;

        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int area = nums[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
