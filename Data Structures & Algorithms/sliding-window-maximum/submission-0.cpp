class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        for (int r = 0; r < nums.size(); r++) {
            while (!dq.empty() && dq.front() <= r - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            if (r - k + 1 >= 0) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
