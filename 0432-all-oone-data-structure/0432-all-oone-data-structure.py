class AllOne:

    def __init__(self):
        #dictionary to store count of strings
        self.d={}
        #previous operation
        self.op=0
        #previous operation result
        self.res=""

    def inc(self, key: str) -> None:
        #reset operation
        self.op=0
        if (key in self.d):
            self.d[key]+=1
        else:
            self.d[key]=1
        return None
    def dec(self, key: str) -> None:
        #reset operation
        self.op=0
        if (self.d[key]>1):
            self.d[key]-=1
        else:
            del self.d[key]
        return None

    def getMaxKey(self) -> str:
        #if previous operation is getMaxKey return previous result
        if (self.op==1):
            return self.res
        self.op=1
        if (self.d):
            a=list(self.d.values())[0]
            b=list(self.d.keys())[0]
            for i in self.d.keys():
                if (self.d[i]>a):
                    a=self.d[i]
                    b=i
            self.res=b
            return b
        self.res=""
        return ""

    def getMinKey(self) -> str:
        #if previous operation is getMinKey return previous result
        if (self.op==2):
            return self.res
        self.op=2
        if (self.d):
            a=list(self.d.values())[0]
            b=list(self.d.keys())[0]
            for i in self.d.keys():
                if (self.d[i]<a):
                    a=self.d[i]
                    b=i
            self.res=b
            return b
        self.res=""
        return ""


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()