class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        # Step 1: Create adjacency list
        adj = [[] for _ in range(n)]  # Initialize adjacency list
        for i, (a, b) in enumerate(edges):
            adj[a].append((b, succProb[i]))  # Add neighbor and edge probability to adjacency list of node 'a'
            adj[b].append((a, succProb[i]))  # Add neighbor and edge probability to adjacency list of node 'b'

        # Step 2: Initialize probabilities
        probabilities = [0] * n  # Initialize probability array
        probabilities[start] = 1  # Set probability of start node to 1

        # Step 3: Initialize priority queue
        pq = []  # Initialize priority queue
        heapq.heappush(pq, (-1, start))  # Push start node to priority queue with probability -1 (negative for max heap)

        # Step 4: Dijkstra's algorithm
        while pq:
            probability, node = heapq.heappop(pq)  # Pop node with highest probability from priority queue
            probability *= -1  # Invert probability back to positive

            if node == end:  # If end node is reached, return the probability
                return probability

            if probability < probabilities[node]:  # If a lower probability is already recorded, skip this node
                continue

            for neighbor, edge_prob in adj[node]:  # Iterate through neighbors of the current node
                new_prob = probability * edge_prob  # Calculate the new probability to reach the neighbor
                if new_prob > probabilities[neighbor]:  # If the new probability is higher than the recorded probability
                    probabilities[neighbor] = new_prob  # Update the probability of reaching the neighbor
                    heapq.heappush(pq, (-new_prob, neighbor))  # Push the neighbor to the priority queue with the new probability

        # Step 5: No path found
        return 0