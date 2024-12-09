class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> list;
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (list.count(nums[i]) == 0) {
                list.insert(nums[i]);
                nums[k] = nums[i]; 
                k++;
            }
        }
        return k;
    }
};
