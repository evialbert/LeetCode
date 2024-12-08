class Solution:
    def minOperations(self, A, k):
        return (lambda a: -1 if a[0] < k else len(a) - int(a[0] == k))(sorted(set(A))) 