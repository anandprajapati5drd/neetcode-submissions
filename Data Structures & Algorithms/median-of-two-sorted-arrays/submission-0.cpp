class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0;

        int n = nums1.size() + nums2.size();
        vector<int> ans(n);
        int i = 0;
        int j = 0;
        int k = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                ans[k] = nums1[i];
                i++;
            }else{
                ans[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i < nums1.size()){
            ans[k] = nums1[i];
            i++;
            k++;
        }
        while(j < nums2.size()){
            ans[k] = nums2[j];
            j++;
            k++;
        }

        if(n % 2 == 0){
            res = (ans[n/2 - 1] + ans[n/2])/2.0;
        }else{
            res = ans[n/2];
        }
        return res;
    }
};
