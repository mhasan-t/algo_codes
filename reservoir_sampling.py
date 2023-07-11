selected = head.val
i = 1
while head:
    if (random.randint(1,100)/100) <= (1/i):
        selected = head.val
    i +=1
    head = head.next

return selected
