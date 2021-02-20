class Solution:
    
    
    def gen_next_words(self, word):
        for i in range(len(word)):
            for c in self.alphabets:
                yield word[:i] + c + word[i + 1:]
    
    
    def dfs(self, start, end, current_path):
        path = current_path + (end,)

        if end == start:
            self.result.append(list(reversed(path)))
        else:
            for parent in self.prev[end]:
                self.dfs(start, parent, path)
                
                
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordList = set(wordList)
        self.alphabets = {c for word in wordList for c in word}

        distance = defaultdict(lambda: float('inf'))

        # Store the child to parent (one to many) relationship.
		# There can be multiple ways to reach a word.
        self.prev = defaultdict(set)

        distance[beginWord] = 0
        found = False
        queue = deque([beginWord])

        while queue:

            current = queue.popleft()

            for child in self.gen_next_words(word=current):
			
			    # If the child is not yet discovered 
                if distance[child] == float('inf') and child in wordList:
                    queue.append(child)
                    distance[child] = distance[current] + 1
                    self.prev[child].add(current)
				# we have discovered one-to-many relationship
                elif distance[child] == distance[current] + 1:
                    self.prev[child].add(current)

                if child == endWord:
                    found = True

        self.result = []

        if found:
            self.dfs(start=beginWord, end=endWord, current_path=())
        
        return self.result
            