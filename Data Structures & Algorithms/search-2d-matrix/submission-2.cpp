class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int st = 0;
        int end = row-1;

        while(st <= end){
            int mid = (end + st)/2;

            if(target >= matrix[mid][0] && target <= matrix[mid][col-1]){
                int l = 0;
                int r = col-1;

                while(l <= r){
                    int m = (l+r)/2;
                    if(matrix[mid][m] == target){
                        return true;
                    }else if(target > matrix[mid][m]){
                        l = m+1;
                    }else{
                        r = m-1;
                    }
                }
                return false;
            }else if(matrix[mid][col-1] > target){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return false;
    }
};
