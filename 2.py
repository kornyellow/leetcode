#!/usr/bin/env python
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ret = ListNode()
        n = ret
        while True:
            if l1 == None and l2 == None:
                return ret
            if l1 == None:
                l1 = l2
                l2 = None
            if l2 == None:
                s = l1.val
            else:
                s = l1.val + l2.val
            n.val = s % 10
            r = s // 10
            if r != 0:
                if l1.next != None:
                    l1.next.val += r
                else:
                    l1.next = ListNode(r)
            l1 = l1.next
            if l2 != None:
                l2 = l2.next
            if l1 != None or l2 != None:
                n.next = ListNode()
                n = n.next

def to_listnode(l):
    ret = ListNode()
    n = ret
    while True:
        if len(l) == 0:
            return ret
        n.val = l[0]
        l.pop(0)
        if len(l) != 0:
            n.next = ListNode()
            n = n.next

def to_list(l):
    ret = []
    while True:
        if l == None:
            return ret
        ret.append(l.val)
        l = l.next

if __name__ == "__main__":
    s = Solution()

    assert to_list(s.addTwoNumbers(to_listnode([2,4,3]), to_listnode([5,6,4]))) == [7,0,8]
    print("Test 1 passed!")
    assert to_list(s.addTwoNumbers(to_listnode([9,9,9,9,9,9,9]), to_listnode([9,9,9,9]))) == [8,9,9,9,0,0,0,1]
    print("Test 2 passed!")
    assert to_list(s.addTwoNumbers(to_listnode([0]), to_listnode([7,8]))) == [7,8]
    print("Test 3 passed!")
