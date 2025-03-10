class Solution:
    def maxWeight(self, pizzas: List[int]) -> int:

        pizzas.sort()
        # hs = defaultdict(int)
        # q = deque(pizzas)
        # seen = set()
        # for i in range(len(pizzas)):
        #     hs[pizzas[i]] += 1
        #     if pizzas[i] not in seen and hs[pizzas[i]] > 1:
        #         seen.add(pizzas[i])

        # print(hs, seen)
        # tmp = 1
        # for i in range(len(pizzas) // 4):
        #     if tmp == 1:
        #         sm += q.pop()
        #         for _ in range(3):
        #             q.pop()
        #         tmp = 0
        #         else:
        
        q = deque(pizzas)
        sm = 0
        tmp = 1
        times = (len(pizzas) // 4) // 2 +  (len(pizzas) // 4) % 2
        # print(times)
        for _ in range(times):
            sm += q.pop()
            for _ in range(3):
                q.popleft()

        while q:
            q.pop()
            sm += q.pop()
            for _ in range(2):
                q.popleft()     

        return sm
                
            
            
        