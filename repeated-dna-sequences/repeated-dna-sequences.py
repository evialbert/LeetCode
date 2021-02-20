class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        dna_sequences = defaultdict()
        
        for i in range(len(s) - 9):
            if s[i: i + 10] in dna_sequences:
                dna_sequences[s[i: i + 10]] += 1
            else:
                dna_sequences[s[i: i + 10]] = 1
                
        
        return [seq for seq, num in dna_sequences.items() if num > 1]