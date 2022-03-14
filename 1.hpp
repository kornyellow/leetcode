class Solution {
public:
	vector <int> twoSum(vector <int> &nums, int target) {
		int numsSize = nums.size();

		unordered_map <int, int> answerMap;
		for (int i = 0; i < numsSize; i++) {
			if (answerMap.find(nums[i]) != answerMap.end()) {
				if (answerMap[nums[i]] == i) continue;
				return {i, answerMap[nums[i]]};
			}
			answerMap[target - nums[i]] = i;
		}
		return {0, 0};
	}
};
