class Solution:
    def numberOfComponents(self, properties, k):
        n, m, dict1, dict2 = len(properties), len(properties[0]), {}, defaultdict(int)

        def find(x):
            if x not in dict1:
                return x 
            else:
                if x != dict1[x]:
                    dict1[x] = find(dict1[x])
                return dict1[x]

        def union(x,y):
            a, b = find(x), find(y)

            if a != b:
                dict1[b] = a 

        for i in range(n):
            for j in range(n):
                if i != j and len(set(properties[i])&set(properties[j])) >= k:
                    union(i,j)

        for i in range(n):
            dict2[find(i)] += 1 

        return len(dict2) 