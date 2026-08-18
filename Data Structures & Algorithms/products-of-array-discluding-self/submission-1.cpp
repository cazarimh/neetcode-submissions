class Solution {
public:
    pair<int, int> verifyZeros(vector<int> nums) {
        int zeroIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (zeroIndex != -1) return {2, -1};
                zeroIndex = i;
            }
        }

        if (zeroIndex != -1) return {1, zeroIndex};

        return {0, -1};
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        auto [zeroNum, index] = verifyZeros(nums);

        if (zeroNum == 2) return res;

        if (zeroNum == 1) {
            res[index] = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (i != index) res[index] *= nums[i];
            }
            return res;
        }

        int total = 1;
        for (auto num: nums) total *= num;

        for (int i = 0; i < res.size(); i++) res[i] = total / nums[i];

        return res;
    }
};
