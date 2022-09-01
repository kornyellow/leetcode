#!/usr/bin/env python

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        opn_braces = "([{"
        cls_braces = ")]}"
        for e in s:
            if e in opn_braces:
                stack.append(e)
            elif e in cls_braces:
                if len(stack) == 0:
                    return False
                if opn_braces.index(stack[-1]) == cls_braces.index(e):
                    stack.pop()
                else:
                    return False
        return len(stack) == 0

if __name__ == "__main__":
    s = Solution()

    assert s.isValid("()") == True
    print("Test 1 pass!")
    assert s.isValid("()[]{}") == True
    print("Test 2 pass!")
    assert s.isValid("(]") == False
    print("Test 3 pass!")
    assert s.isValid("[") == False
    print("Test 4 pass!")
    assert s.isValid("]") == False
    print("Test 5 pass!")
