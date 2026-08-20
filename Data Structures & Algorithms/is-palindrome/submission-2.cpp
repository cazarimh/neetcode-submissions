class Solution {
   public:
    bool isPalindromeRec(string s, int n) {
        if (n == 0 || n == 1) return true;

        return s[0] == s[n - 1] && isPalindromeRec(s.substr(1, n - 2), n - 2);
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
        return isPalindromeRec(t, t.length());
    }
};
