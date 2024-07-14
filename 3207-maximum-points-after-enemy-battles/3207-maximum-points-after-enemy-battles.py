class Solution:
    def maximumPoints(self, enemyEnergies: List[int], currentEnergy: int) -> int:
        enemyEnergies.sort()
        points = 0
        i, j = 0, len(enemyEnergies) - 1
        
       
        while i <= j:
            if currentEnergy >= enemyEnergies[i]:
                points += (currentEnergy // enemyEnergies[i])
                currentEnergy = (currentEnergy % enemyEnergies[i])
               
            elif points > 0:
                currentEnergy += enemyEnergies[j]
                j -= 1
            else:
                break
                
        return points