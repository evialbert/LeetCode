class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        max=arr[1]-arr[0]
        result=[[arr[0],arr[1]]]
        for i in range(1,len(arr)-1):
            if arr[i+1]-arr[i]<max:
                max=arr[i+1]-arr[i]
                result.clear()
                result.append([arr[i],arr[i+1]])
            elif arr[i+1]-arr[i]==max:
                result.append([arr[i],arr[i+1]])
        return result