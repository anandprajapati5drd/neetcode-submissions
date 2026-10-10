class Solution {
public:
    vector<string> store;
    string encode(vector<string>& strs) {
        string s = "";
        for(int i=0; i<strs.size(); i++){
            s += strs[i];
            store.push_back(strs[i]);
        }
        return s;
    }

    vector<string> decode(string s) {
        return store;
    }
};
