def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
	if not head:
	    return None
	if not head.next:
	    return None
	if not head.next.next:
	    return None
	if head.next.next is head:
	    return head 

	slow = head
	fast = head
	cycle = False
	pos = 0
	while slow:
	    if not fast.next or not fast.next.next:
		    return None

	    slow = slow.next
	    fast = fast.next.next
	    pos += 1

	    if slow==fast:
		    cycle = True
		    break

	if cycle:
	    slow = head
	    while slow is not fast:
		    slow = slow.next
		    fast = fast.next
	        return slow
	return None
