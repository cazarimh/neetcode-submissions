class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> existingNums;
        for (auto num: nums) {
            if (existingNums.contains(num)) return true;
            existingNums.insert(num);
        }
        return false;
    }
};