#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        // We need to pick k-1 more elements from a window of size dist + 1.
        // The first of these elements is nums[i], and the others must be 
        // within dist indices of it.
        int m = k - 1; 
        long long current_sum = 0;
        multiset<int> left, right;

        // Helper to maintain the smallest 'm' elements in 'left'
        auto add = [&](int val) {
            left.insert(val);
            current_sum += val;
            if (left.size() > m) {
                int to_move = *left.rbegin();
                current_sum -= to_move;
                right.insert(to_move);
                left.erase(prev(left.end()));
            }
        };

        auto remove = [&](int val) {
            auto it = left.find(val);
            if (it != left.end()) {
                current_sum -= val;
                left.erase(it);
                if (!right.empty()) {
                    int to_move = *right.begin();
                    current_sum += to_move;
                    left.insert(to_move);
                    right.erase(right.begin());
                }
            } else {
                right.erase(right.find(val));
            }
        };

        // The window size is dist + 1. It starts at index 1.
        // We look at the window [1, dist + 1].
        for (int i = 1; i <= dist + 1; ++i) {
            add(nums[i]);
        }

        long long min_cost = nums[0] + current_sum;

        // Slide the window. The window is [i, i + dist]
        // In the first iteration, i was 1, so the window was [1, 1 + dist].
        // Next, i becomes 2, window is [2, 2 + dist].
        for (int i = 2; i <= n - 1; ++i) {
            // Remove the element that is no longer reachable: nums[i-1]
            remove(nums[i - 1]);

            // Add the new element that just came into range: nums[i + dist]
            if (i + dist < n) {
                add(nums[i + dist]);
            }

            // Only update if we have enough elements to satisfy k-1
            if (left.size() == m) {
                min_cost = min(min_cost, (long long)nums[0] + current_sum);
            }
        }

        return min_cost;
    }
};