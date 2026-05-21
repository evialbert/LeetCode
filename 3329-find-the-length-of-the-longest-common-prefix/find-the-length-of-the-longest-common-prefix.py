class TrieNode:
    def __init__(self):
        # Each node has up to 10 possible children (digits 0-9)
        self.children = [None] * 10


class Trie:
    def __init__(self):
        self.root = TrieNode()

    # Insert a number into the Trie by treating it as a string of digits
    def insert(self, num):
        node = self.root
        num_str = str(num)
        for digit in num_str:
            idx = int(digit)
            if not node.children[idx]:
                node.children[idx] = TrieNode()
            node = node.children[idx]

    # Find the longest common prefix for a number in arr2 with the Trie
    def find_longest_prefix(self, num):
        node = self.root
        num_str = str(num)
        len = 0

        for digit in num_str:
            idx = int(digit)
            if node.children[idx]:
                # Increase length if the current digit matches
                len += 1
                node = node.children[idx]
            else:
                # Stop if no match for the current digit
                break
        return len


class Solution:
    def longestCommonPrefix(self, arr1, arr2):
        trie = Trie()

        # Step 1: Insert all numbers from arr1 into the Trie
        for num in arr1:
            trie.insert(num)

        longest_prefix = 0

        # Step 2: Find the longest prefix match for each number in arr2
        for num in arr2:
            len = trie.find_longest_prefix(num)
            longest_prefix = max(longest_prefix, len)

        return longest_prefix