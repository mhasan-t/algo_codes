def get_height(node):
    height = 0
    q = [node]
    while q:
        newq = []
        for node in q:
            if node.left:
                newq.append(node.left)
            if node.right:
                newq.append(node.right)
        q = newq
        height += 1
    return height
