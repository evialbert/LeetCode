class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        output=[] 
        people.sort(key=lambda x: (-x[0], x[1]))                
        for a in people:
            output.insert(a[1], a)  
        return output