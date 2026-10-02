class Solution {
public:
    void backtrack(vector<string>& ans, string digits, int idx, string curr, string mapping[]){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
       
        int number = digits[idx] - '0';
        string val = mapping[number];

        for(int i=0; i<val.size(); i++){
            curr.push_back(val[i]);
            backtrack(ans, digits, idx+1, curr, mapping);
            curr.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;

        backtrack(ans, digits, 0, "", mapping);

        return ans;
    }
};
