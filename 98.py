#!/usr/bin/env python
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.check(root)
    def check(self, root: Optional[TreeNode], l=-2E31, h=2E31) -> bool:
        if root is None:
            return True
        if root.val < l or root.val > h:
            return False
        return (self.check(root.left, l, root.val-1)) and (self.check(root.right, root.val+1, h))

def to_tree(l, i=0):
    if i >= len(l) or l[i] == None:
        return None
    d = l[i]
    lf = (i*2)+1
    rt = lf+1
    t = TreeNode(d)
    t.left = to_tree(l, lf)
    t.right = to_tree(l, rt)
    return t

if __name__ == "__main__":
    s = Solution()

    assert s.isValidBST(to_tree([2,1,3])) == True
    print("Test 1 pass!")
    assert s.isValidBST(to_tree([5,1,4,None,None,3,6])) == False
    print("Test 2 pass!")
    assert s.isValidBST(to_tree([2,2,2])) == False
    print("Test 3 pass!")
    assert s.isValidBST(to_tree([5,4,6,None,None,3,7])) == False
    print("Test 4 pass!")
    assert s.isValidBST(to_tree([3,1,5,0,2,4,6])) == True
    print("Test 5 pass!")
