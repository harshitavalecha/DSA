class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            int distinctEven = 0, distinctOdd = 0;

            for (int j = i; j < n; j++) {
                // if number appears first time in this subarray
                if (freq[nums[j]] == 0) {
                    if (nums[j] % 2 == 0)
                        distinctEven++;
                    else
                        distinctOdd++;
                }

                freq[nums[j]]++;

                if (distinctEven == distinctOdd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
