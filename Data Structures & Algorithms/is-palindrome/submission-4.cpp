class Solution {
   public:
    bool isPalindromeRec(string& s, int l, int r) {
        int n = r - l + 1;
        if (n == 0 || n == 1) return true;

        return s[l] == s[r] && isPalindromeRec(s, l + 1, r - 1);
    }

    void toLowerCase(string& s) {
        for (int i = 0; i < s.length(); i++)
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += ('a' - 'A');
    }

    void toAlphanumeric(string& s) {
        string t = "";
        t.reserve(s.length());

        for (auto c : s) {
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9') t += c;
        }

        s = t.substr();
    }

    bool isPalindrome(string s) {
        string t = s.substr();
        toAlphanumeric(t);
        toLowerCase(t);
        return isPalindromeRec(t, 0, t.length() - 1);
    }
};
