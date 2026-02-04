#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        
        // s1[i]: Max sum of an increasing subarray ending at i (length >= 2)
        // Represents nums[l...p]
        vector<long long> s1(n, LLONG_MIN);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                // Option 1: Start a new increasing pair (nums[i-1], nums[i])
                long long opt1 = (long long)nums[i - 1] + nums[i];
                // Option 2: Extend an existing increasing subarray
                long long opt2 = (s1[i - 1] == LLONG_MIN) ? LLONG_MIN : s1[i - 1] + nums[i];
                s1[i] = max(opt1, opt2);
            }
        }

        // s2[i]: Max sum of an increasing-then-decreasing subarray ending at i
        // Represents nums[l...p...q]
        vector<long long> s2(n, LLONG_MIN);
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                // Option 1: i-1 was the peak 'p' (transition from s1)
                long long opt1 = (s1[i - 1] == LLONG_MIN) ? LLONG_MIN : s1[i - 1] + nums[i];
                // Option 2: Continue the decrease (transition from s2)
                long long opt2 = (s2[i - 1] == LLONG_MIN) ? LLONG_MIN : s2[i - 1] + nums[i];
                s2[i] = max(opt1, opt2);
            }
        }

        // s3[i]: Max sum of a full trionic subarray ending at i
        // Represents nums[l...p...q...r]
        vector<long long> s3(n, LLONG_MIN);
        long long ans = LLONG_MIN;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                // Option 1: i-1 was the valley 'q' (transition from s2)
                long long opt1 = (s2[i - 1] == LLONG_MIN) ? LLONG_MIN : s2[i - 1] + nums[i];
                // Option 2: Continue the final increase (transition from s3)
                long long opt2 = (s3[i - 1] == LLONG_MIN) ? LLONG_MIN : s3[i - 1] + nums[i];
                s3[i] = max(opt1, opt2);
            }
            if (s3[i] > ans) ans = s3[i];
        }

        return ans;
    }
};
