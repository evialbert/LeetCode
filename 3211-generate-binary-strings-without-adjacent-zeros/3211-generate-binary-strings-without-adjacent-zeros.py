class Solution:
    def validStrings(self, n: int) -> List[str]:
        
        dp_dict = {}
        
        dp_dict[1] = ["1","0"]
        
        for i in range(2, n+1):
            
            p_list = dp_dict[i-1]
            
            c_list = []
            
            for p_str in p_list:
                
                if(p_str[-1] == '0'):
                    c_list.append(p_str+'1')
                else:
                    c_list.append(p_str+'0')
                    c_list.append(p_str+'1')
                
            dp_dict[i] = c_list
        
        return dp_dict[n]
            