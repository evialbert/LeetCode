class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        
        ans = []
        i = 0
        while (i + k) - 1 < len(nums):
            tmp = x
            hs = Counter(nums[i:i + k])
            h = defaultdict(set)
            for o in hs:
                h[hs[o]].add(o)
            sm = 0
            while tmp != 0:
                tm = 0
                for o in reversed(sorted(h)):
                    if len(h[o]) > 0:
                        tm = o
                        break
                if not h[tm]:
                    break
                mx = max(h[tm])
                h[tm].remove(mx)
                sm += (tm * mx)
                tmp -= 1
            ans.append(sm)
            i += 1
        return ans