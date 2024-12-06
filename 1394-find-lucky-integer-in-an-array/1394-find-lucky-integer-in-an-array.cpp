class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxLucky=-1;
        for(int i=0; i<arr.size(); i++){
            int count=0;
            int lucky = arr[i];
            for(int j=0; j<arr.size(); j++){
                if(lucky==arr[j]){
                    count++;
                }
            }
            if(count == lucky && lucky>maxLucky){
                maxLucky = lucky;
            }
        }
        return maxLucky;
    }
};