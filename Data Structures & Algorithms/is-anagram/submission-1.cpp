class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> sCount, tCount;
        sCount.assign(26, 0); tCount.assign(26, 0);

        for (int i = 0; i < s.length(); i++) {
            sCount[s[i] - 'a']++; tCount[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (sCount[i] != tCount[i]) return false;
        }

        return true;
    }
};
