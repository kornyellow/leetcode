class Solution {
public:
	int search(vector<int>& nums, int target) {
		int old_pivot = -1;
		int pivot = 0;
		int start = 0, end = nums.size() - 1;
		while (pivot != old_pivot) {
			old_pivot = pivot;
			pivot = start + ((end - start) / 2);
			if (nums[pivot] == target) return pivot;
			else if (target < nums[pivot]) {
				end = pivot;
			} else {
				start = pivot;
			}
		}
		return -1;
	}
};