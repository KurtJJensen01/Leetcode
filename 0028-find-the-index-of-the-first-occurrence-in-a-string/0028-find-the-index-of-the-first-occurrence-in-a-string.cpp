class Solution {
public:
    int strStr(string haystack, string needle) {
        int nSize = needle.length();
        if (nSize == 0){
            return 0;
        }
        if(needle.length()>haystack.length()){
            return -1;
        }
        
        for (int i = 0; i <= haystack.length() - nSize; i++) {
            if (haystack.substr(i, nSize) == needle) {
                return i; 
            }
        }
        return -1;
    }
};
