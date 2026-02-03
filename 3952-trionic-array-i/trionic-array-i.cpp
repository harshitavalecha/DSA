class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;

        // 1️⃣ strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        // need at least one increase and not at end
        if (i == 0 || i == n - 1) return false;

        // 2️⃣ strictly decreasing
        int p = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        // must decrease at least once and not reach end
        if (i == p || i == n - 1) return false;

        // 3️⃣ strictly increasing again
        int q = i;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        // must increase at least once and reach end
        return (i > q && i == n - 1);
    }
};
