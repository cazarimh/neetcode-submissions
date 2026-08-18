class Solution {
public:
    // time: O(n*log(n)), space: O(n)
    // time turns O(n) with bucket
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (auto num: nums) {
            if (frequency.contains(num)) frequency[num]++;
            else frequency[num] = 1;
        }

        vector<vector<int>> freqBucket(nums.size()+1);
        for (auto [num, freq]: frequency) freqBucket[freq].push_back(num);

        vector<int> res;
        res.reserve(k);

        for (int i = nums.size(); i >= 0; i--) {
            res.insert(res.end(), freqBucket[i].begin(), freqBucket[i].end());
            if (res.size() == k) break;
        }

        return res;
    }
};
