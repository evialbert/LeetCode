class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
         
        meetings.sort()
        hashmap = defaultdict(int)
        heap = [[0, i] for i in range(n)]
        heapify(heap)

        for start, end in meetings:
            for i in range(n):
                if heap[i][0] <= start:
                    heap[i][0] = 0
            heapify(heap)
            if heap[0][0] <= start:
                hashmap[heap[0][1]] += 1
                heappushpop(heap, [end, heap[0][1]])
            else:
                hashmap[heap[0][1]] += 1
                heappushpop(heap, [end - start + heap[0][0], heap[0][1]])

        res = hashmap[0]
        output = 0
        for key in hashmap:
            if res < hashmap[key]:
                output = key
                res = hashmap[key]
            elif res == hashmap[key]:
                output = min(key, output)
        
        return output