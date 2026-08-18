class Solution {
public:
    // time: O(mn), space: O(m)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (auto str: strs) {
            vector<int> count(26, 0);
            for (auto chr: str) count[chr - 'a']++;

            string key = to_string(count[0]);
            for (auto n: count) key += ',' + to_string(n);

            anagrams[key].push_back(str);
        }

        vector<vector<string>> res;
        for (auto [key, arr]: anagrams) res.push_back(arr);

        return res;
    }
};
