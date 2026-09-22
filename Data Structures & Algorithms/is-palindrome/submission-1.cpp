class Solution {
public:
    bool isalphanum(char c){
        if((c <= '9' && c >= '0') || (c <= 'Z' && c >= 'A') || (c >= 'a' && c <= 'z')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int l=0; 
        int r=s.size()-1;

        while(l <= r){
            while(l < r && !isalphanum(s[l])) l++;
            while(r > l && !isalphanum(s[r])) r--;

                        if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            

            l++;
            r--;
        }
        return true;
    }
};
