#!/usr/bin/env python
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i, v in enumerate(nums):
            if v in m:
                return [m[v], i]
            m[target - v] = i

if __name__ == "__main__":
    s = Solution()

    assert s.twoSum([3, 3], 6) == [0, 1]
    print("Test 1 pass!")
    assert s.twoSum([3, 2, 4], 6) == [1, 2]
    print("Test 2 pass!")
