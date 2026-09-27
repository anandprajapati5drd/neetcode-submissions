class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l=0;
        int length = 0;

        for(int r=0; r<s.size(); r++){
            mp[s[r]]++;
            if(mp[s[r]] == 1){
                length = max(length, r-l+1);
            }
            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
                if(mp[s[r]] == 0){
                    mp.erase(s[l]);
                }
            }
        }
        return length;
    }
};
