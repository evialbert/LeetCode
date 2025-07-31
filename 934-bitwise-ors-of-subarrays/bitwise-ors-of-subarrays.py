class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        res = set()
        curr = set()

        for num in arr:
            # For each number, update the current set of ORs by OR-ing it with previous values
            curr = {num | x for x in curr} | {num}
            res |= curr  # Add all current ORs to the result set

        return len(res)