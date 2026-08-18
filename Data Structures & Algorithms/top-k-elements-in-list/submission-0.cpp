class Solution {
public:
    // time: O(n*log(n)), space: O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;

        for (auto num: nums) {
            if (frequency.contains(num)) frequency[num]++;
            else frequency[num] = 1;
        }

        vector<pair<int, int>> freqArr;
        for (auto [num, freq]: frequency) freqArr.push_back({-freq, num});

        sort(freqArr.begin(), freqArr.end());

        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(freqArr[i].second);

        return res;
    }
};
