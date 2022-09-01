#!/usr/bin/env python

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x <= 9:
            return True
        l = []
        r = x % 10
        x = x // 10
        while x != 0 or r != 0:
            l.append(r)
            r = x % 10
            x = x // 10
        n = len(l)
        for a in range(n//2):
            if l[a] != l[n-a-1]:
                return False
        return True

if __name__ == "__main__":
    s = Solution()
    assert s.isPalindrome(121) == True
    print("Test 1 pass!")
    assert s.isPalindrome(-121) == False
    print("Test 2 pass!")
    assert s.isPalindrome(10) == False
    print("Test 3 pass!")
    assert s.isPalindrome(12321) == True
    print("Test 4 pass!")
