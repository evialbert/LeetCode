class Solution:
    def maxAmount(self, initialCurrency: str, pairs1: List[List[str]], rates1: List[float], pairs2: List[List[str]], rates2: List[float]) -> float:
        
        day1Exchange = defaultdict(list)
        for ind, val in enumerate(pairs1):
            init, tar = val
            day1Exchange[init].append([tar, rates1[ind]])
            day1Exchange[tar].append([init, 1 / rates1[ind]])
            
        day2Exchange = defaultdict(list)
        for ind, val in enumerate(pairs2):
            init, tar = val
            day2Exchange[init].append([tar, rates2[ind]])
            day2Exchange[tar].append([init, 1 / rates2[ind]])
            
        vis = set()
        q = collections.deque([[initialCurrency,1]])
        
        all_posibilities_of_day1 = []
        while q:
            current_currency, value = q.popleft()
            all_posibilities_of_day1.append([current_currency, value])
            vis.add(current_currency)
            for nxt, rate in day1Exchange[current_currency]:
                if nxt not in vis:
                    q.append([nxt, value * rate])
                    
        res = 1
        for day1_curr, val in all_posibilities_of_day1:
            vis = set()
            q = collections.deque([[day1_curr,val]])
            while q:
                current_currency, value = q.popleft()
                if current_currency == initialCurrency:
                    res = max(res, value)
                vis.add(current_currency)
                for nxt, rate in day2Exchange[current_currency]:
                    if nxt not in vis:
                        q.append([nxt, value * rate])
        return res