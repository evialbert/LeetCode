class TrieNode:
    # save some memory
    __slots__ = ['children', 'cnt']
    def __init__(self):
        self.children = [None, None]
        self.cnt = 0

class Solution:
    def maxXor(self, nums: list[int], k: int) -> int:
        ##
        n = len(nums)
        if n == 0:
            return 0
        
        # 1. Prefix XORs: pref[i+1] = nums[0] ^ ... ^ nums[i]
        pref = [0] * (n + 1)
        for i in range(n):
            pref[i+1] = pref[i] ^ nums[i]
            
        # 2. Optimized Trie with deletion support
        root = TrieNode()
        
        def insert(val):
            node = root
            for i in range(15, -1, -1):
                bit = (val >> i) & 1
                if not node.children[bit]:
                    node.children[bit] = TrieNode()
                node = node.children[bit]
                node.cnt += 1
        
        def remove(val):
            node = root
            for i in range(15, -1, -1):
                bit = (val >> i) & 1
                node = node.children[bit]
                node.cnt -= 1
        # find a number currently stored in the Trie that, when XORed with val (which is pref[r+1]), produces the largest possible result.
        def query(val):
            node = root
            res = 0
            for i in range(15, -1, -1):
                bit = (val >> i) & 1
                desired = 1 - bit
                # Prefer the branch that gives 1 for this bit
                if node.children[desired] and node.children[desired].cnt > 0:
                    res |= (1 << i)
                    node = node.children[desired]
                elif node.children[bit] and node.children[bit].cnt > 0:
                    node = node.children[bit]
                else:
                    return 0
            return res

        # 3. Sliding Window with mono Deques
        min_dq = deque()  # stores indices for minimum tracking
        max_dq = deque()  # stores indices for maximum tracking
        left = 0
        ans = 0
        
        for r in range(n):
            # Maintain monotonic deques for min/max in nums[left...r]
            while min_dq and nums[min_dq[-1]] >= nums[r]:
                min_dq.pop()
            min_dq.append(r)
            
            while max_dq and nums[max_dq[-1]] <= nums[r]:
                max_dq.pop()
            max_dq.append(r)
            
            # Add pref[r] to the trie (potential start index l=r)
            insert(pref[r])
            
            # Shrink window if max - min > k
            while nums[max_dq[0]] - nums[min_dq[0]] > k:
                remove(pref[left])
                left += 1
                if min_dq[0] < left:
                    min_dq.popleft()
                if max_dq[0] < left:
                    max_dq.popleft()
            
            # Query max(pref[r+1] ^ pref[l]) for all valid l in [left, r]
            ans = max(ans, query(pref[r+1]))
            
        return ans