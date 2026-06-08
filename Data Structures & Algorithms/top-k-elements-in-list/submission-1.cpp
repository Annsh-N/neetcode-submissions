class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& pair : frequency) {
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        vector<int> result;

        for (int freq = nums.size(); freq > 0; freq--) {
            for (int num : buckets[freq]) {
                result.push_back(num);
            }

            if (result.size() == k) {
                return result;
            }
        }

        return result;

    }
};
