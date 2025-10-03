class Solution {
public:
    int search(vector<int>& nums, int target) {
            int start = 0, end = nums.size() - 1;

            while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) return mid;

            // Check if left half is sorted
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1; // target in left half
                } else {
                    start = mid + 1; // target in right half
                }
            }
            // Otherwise right half is sorted
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1; // target in right half
                } else {
                    end = mid - 1; // target in left half
                }
            }
        }
        return -1;

    }
};