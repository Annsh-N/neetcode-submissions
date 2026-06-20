class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lMax = 0;
        int rMax{0};
        int water = 0;

        while (l < r) {
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);

            if (lMax < rMax) {
                water += lMax - height[l];
                l++;
            } else {
                water += rMax - height[r];
                r--;
            }
        }

        return water;
        
    }
};
