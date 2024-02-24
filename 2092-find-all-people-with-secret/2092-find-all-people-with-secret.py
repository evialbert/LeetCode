class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        # Append the initial meeting for the first person
        meetings.append([firstPerson, 0, 0])
        
        # Create the graph of meetings
        graph = defaultdict(lambda: defaultdict(list))
        for person1, person2, time in meetings:
            graph[person1][time].append(person2)
            graph[person2][time].append(person1)
        
        # Initialize a priority queue to process meetings
        pq = [(0, 0)]  # (time, person)
        
        # Initialize a set to store persons with the secret
        visited = set()
        
        while pq:
            curr_time, person = heapq.heappop(pq)
            if person in visited:
                continue
            visited.add(person)
            for time, persons in graph[person].items():
                if time >= curr_time:
                    for second_person in persons:
                        if second_person not in visited:
                            heapq.heappush(pq, (time, second_person))
        
        return list(visited)