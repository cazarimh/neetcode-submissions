class Solution {
public:
    string itoa(int num, int digits) {
        string strNum = to_string(num);
        while (strNum.size() < digits) strNum = "0" + strNum;
        return strNum;
    }

    int atoi(string str, int base) {
        int res = 0;
        for (auto n: str) {
            res += n - '0';
            res *= base;
        }
        return res/base;
    }

    string encode(vector<string>& strs) {
        string strNum = itoa(strs.size(), 2);
        string res = "" + strNum;

        for (auto str: strs) res += itoa(str.size(), 3);
        for (auto str: strs) res += str;

        return res;
    }

    vector<string> decode(string s) {
        int strNum = atoi(s.substr(0, 2), 10);

        vector<int> strsLengths;
        strsLengths.reserve(strNum);
        for (int i = 0; i < strNum; i++) {
            strsLengths.push_back(atoi(s.substr((3*i)+2, 3), 10));
        }

        vector<string> res;
        res.reserve(strNum);
        int offset = 3*strNum + 2;
        for (auto strLength: strsLengths) {
            res.push_back(s.substr(offset, strLength));
            offset += strLength;
        }
        
        return res;
    }
};
