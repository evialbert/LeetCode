class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        
        n = len(classes)
        impacts = [(p/t - ((p+1)/(t+1)), p, t) for p,t in classes]
        heapq.heapify(impacts)

        for _ in range(extraStudents):
            impact, passes, total = heapq.heappop(impacts)
            passes +=1
            total +=1
            heapq.heappush(impacts, (passes/total - ((passes+1)/(total+1)), passes, total))

        percents = [p/t for _,p,t in impacts]
        return mean(percents)