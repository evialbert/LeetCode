class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        hashset = {}
        answer = []
        tempList = []
        # get the count of integer in arr1
        for i in range(len(arr1)):
            if hashset.get(arr1[i]) == None:
                hashset[arr1[i]] = 1
            else:
                hashset[arr1[i]] += 1
        # append the elements of arr1 to answer in the order of arr2
        for i in arr2:
            if hashset.get(i) != None:
                n = hashset.pop(i)
                while(n > 0):
                    answer.append(i)
                    n -= 1
        # add remaining elements of arr1 to tempList
        for key in hashset:
            n = hashset.get(key)
            while n>0:
                tempList.append(key)
                n -= 1
        tempList.sort()
        return answer+tempList   