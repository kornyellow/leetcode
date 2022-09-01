#!/usr/bin/env python

from typing import Optional

class ListNode:
    def __init__(self, val=0, nxt=None):
        self.val = val
        self.next = nxt

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None:
            return list2
        elif list2 == None:
            return list1

        head1 = list1
        head2 = list2

        head = ListNode()
        curr = head

        while True:
            if head1 == None and head2 == None:
                break

            val1 = head1.val if head1 != None else 101
            val2 = head2.val if head2 != None else 101

            if val1 < val2:
                curr.val = val1
                head1 = head1.next if head1 != None else None
            else:
                curr.val = val2
                head2 = head2.next if head2 != None else None

            if head1 != None or head2 != None:
                curr.next = ListNode()
                curr = curr.next

        return head

def to_listnode(l):
    if len(l) == 0:
        return None

    head = ListNode()
    curr = head
    while True:
        curr.val = l.pop(0)
        if len(l) == 0:
            return head
        curr.next = ListNode()
        curr = curr.next

def to_list(head):
    if head == None:
        return []

    ret = []
    curr = head
    while curr.next != None:
        ret.append(curr.val)
        curr = curr.next
    ret.append(curr.val)
    return ret

if __name__ == "__main__":
    s = Solution()

    assert to_list(s.mergeTwoLists(to_listnode([1,2,4]), to_listnode([1,3,4]))) == [1,1,2,3,4,4]
    print("Test 1 pass!")
    assert to_list(s.mergeTwoLists(to_listnode([]), to_listnode([]))) == []
    print("Test 2 pass!")
    assert to_list(s.mergeTwoLists(to_listnode([0]), to_listnode([]))) == [0]
    print("Test 3 pass!")
