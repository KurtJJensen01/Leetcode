class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int end=str.length()-1;
        for(int i=0; i<str.length()/2; i++){
            if(str[i]!=str[end]){
                return false;
            }
            end--;
        }
        return true;
    }
};