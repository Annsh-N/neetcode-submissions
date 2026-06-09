class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        int product{1};
        for (int i = 1; i < nums.size(); i++) {
            product *= nums[i-1];
            prefix[i] = product;
        }

        vector<int> suffix(nums.size(), 1);
        product = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            product *= nums[i+1];
            suffix[i] = product;
        }

        for (int i = 0; i < nums.size(); i++) {
            prefix[i] *= suffix[i];
        }

        return prefix;

    }
};
