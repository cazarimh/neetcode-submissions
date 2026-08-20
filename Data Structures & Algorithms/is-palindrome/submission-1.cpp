class Solution {
public:
    bool isPalindromeRec(string s, int n) {
        if (n == 0 || n == 1) return true;

        return s[0] == s[n-1] && isPalindromeRec(s.substr(1, n-2), n-2);
    }

    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); i++) if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
        return s;
    }

    string toAlphanumeric(string s) {
        string t = "";
        t.reserve(s.length());

        for (auto c: s) {
            if (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9') t += c;
        }

        return t;
    }

    bool isPalindrome(string s) {
        s = toLowerCase(toAlphanumeric(s));
        return isPalindromeRec(s, s.length());
    }
};
