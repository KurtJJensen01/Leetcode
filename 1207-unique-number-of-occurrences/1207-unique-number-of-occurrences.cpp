class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> frequencyMap;
    
    for (int num : arr) {
        frequencyMap[num]++;
    }
    
    unordered_set<int> frequencies;
    for (const auto& entry : frequencyMap) {
        if (frequencies.find(entry.second) != frequencies.end()) {
            return false;
        }
        frequencies.insert(entry.second);
    }
    
    return true;        
    }
};