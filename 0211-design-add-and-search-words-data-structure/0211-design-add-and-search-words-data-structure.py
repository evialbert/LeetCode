class WordDictionary:

    def __init__(self):
        self.text = []
        

    def addWord(self, word: str) -> None:
        self.text.append(word)
        

    def search(self, word: str) -> bool:
        if '.' not in word:
            return word in self.text

        for t in self.text:
            if len(t) != len(word):
                continue
            for i in range(len(word)):
                if word[i] == '.':
                    continue
                if word[i] != t[i]:
                    break
            else:
                return True
        return False
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)