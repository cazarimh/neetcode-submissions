class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> numsSet;
        for (auto num: nums) numsSet.insert(num);

        vector<int> possibleStarts;
        for (auto num: numsSet) {
            if (!numsSet.contains(num-1)) possibleStarts.push_back(num);
        }

        int lcs = 0;
        for (auto start: possibleStarts) {
            int currentLcs = 0;
            while (numsSet.contains(start++)) currentLcs++;
            lcs = currentLcs > lcs ? currentLcs : lcs;
        }


        return lcs;
    }
};
