class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        answer = [0] * k
        state = [0] * k

        for num in nums:
            # Dont add number to current state
            for i in range(len(state)):
                answer[i] += state[i]
                
            # Add number to current state
            next_state = [0] * k
            for (index, val) in enumerate(state):
                next_index = (index * num) % k
                next_state[next_index] += val

            state = next_state
            state[num % k] += 1
            
        # Account for final number
        for i in range(len(state)):
            answer[i] += state[i]

        return answer
        

                
                
                
                    
                    
        