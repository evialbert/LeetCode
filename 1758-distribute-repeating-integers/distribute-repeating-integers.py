class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:

        # count the amount of same integers
        cn = collections.Counter(collections.Counter(nums).values())
        
        # sort the customers to deal with the most difficult ones first
        quantity.sort(reverse=True)

        # make recursive dfs with memoization
        cache = dict()
        def dfs(items, idx):
            if idx >= len(quantity): return True
            tp_it = frozenset(items.items())
            if (tp_it, idx) not in cache:

                # go though all the frequent items
                result = False
                for qnti, nq in list(items.items()):
                    
                    # check whether we have similar integers
                    if not nq or qnti < quantity[idx]: continue

                    # update our items
                    items[qnti] -= 1
                    items[qnti-quantity[idx]] += 1

                    # recurse deeper
                    if dfs(items, idx+1):
                        result = True
                        break

                    # undo changes to items
                    items[qnti] += 1
                    items[qnti-quantity[idx]] -= 1
                
                # set the cache
                cache[(tp_it, idx)] = result
            return cache[(tp_it, idx)]
        return dfs(cn, 0)

                    

