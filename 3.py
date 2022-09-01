#!/usr/bin/env python

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        a = 0
        b = 0
        l = -1
        m = {s[a]:a}
        while True:
            b += 1
            if b == len(s) or a == len(s):
                break
            if s[a] == s[b] or s[b] in s[a:b]:
                l = b-a if b-a > l else l
                a = m[s[b]]+1
                if s[a] == s[b]:
                    a = b
            m[s[b]] = b
        w = b-a
        return l if l > w else w

if __name__ == "__main__":
    s = Solution()

    assert s.lengthOfLongestSubstring("abcabcab") == 3
    print("Test 1 pass!")
    assert s.lengthOfLongestSubstring("bbbbbbbb") == 1
    print("Test 2 pass!")
    assert s.lengthOfLongestSubstring("pwwkew") == 3
    print("Test 3 pass!")
    assert s.lengthOfLongestSubstring("aab") == 2
    print("Test 4 pass!")
    assert s.lengthOfLongestSubstring("dvdf") == 3
    print("Test 5 pass!")
    assert s.lengthOfLongestSubstring("nfpdmpi") == 5
    print("Test 6 pass!")
    assert s.lengthOfLongestSubstring("ohvhjdml") == 6
    print("Test 7 pass!")
