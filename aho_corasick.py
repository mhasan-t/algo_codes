class Node:
    def __init__(self, parent=None, is_word=False, edge_in=-1) -> None:
        self.transit = {}
        self.parent = parent
        self.suffix: Node = None
        self.is_word = is_word
        self.edge_in = edge_in


class AhoCorasickAutomata:
    def __init__(self) -> None:
        node = Node()
        node.parent = node
        node.suffix = node
        self.trie_root = node
        self.total_nodes = 1

    def add_word(self, word_str):
        node = self.trie_root

        for ch in word_str:
            if node.transit.get(ch) is None:
                node.transit[ch] = Node(parent=node, edge_in=ch)
                self.total_nodes += 1
            node = node.transit[ch]

        node.is_word = True

    def get_suffix(self, node: Node):
        if node.suffix is None:
            if node.parent is self.trie_root:
                node.suffix = self.trie_root
            else:
                node.suffix = self.get_transition(
                    self.get_suffix(node.parent), node.edge_in)
        return node.suffix

    def get_transition(self, node: Node, edge):
        if node.transit.get(edge) is None:

            if node is self.trie_root:
                return node
            node.transit[edge] = self.get_transition(
                self.get_suffix(node), edge)

        return node.transit[edge]

    def print_words_in_string(self, string):
        print("\n*** *** *** *** ***\n")

        node = self.trie_root
        for ch in string:
            temp = node
            node = self.get_transition(node, ch)
            if node.is_word:
                print("word that ends with - ", node.edge_in)

        print("\n*** *** *** *** ***\n")

    def print_trie(self):
        q = [self.trie_root]
        new_level = []

        print("\n*** *** *** *** ***\n")

        while q:
            node = q[0]
            q.pop(0)

            for key, value in node.transit.items():
                if value.is_word:
                    print("("+key+")", value.suffix, end=" | ")
                else:
                    print(key, value.suffix, end=" | ")
                new_level.append(value)

            if not q:
                q, new_level = new_level, []
                print(" ")

        print("\n*** *** *** *** ***\n")


aho = AhoCorasickAutomata()
aho.add_word("java")
aho.add_word("rad")
aho.add_word("rand")
aho.add_word("rau")
aho.add_word("raum")
aho.add_word("rose")
aho.print_trie()
aho.print_words_in_string("javararoserad")
