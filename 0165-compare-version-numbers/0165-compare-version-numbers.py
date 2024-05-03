class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        lst1=version1.split('.')
        lst2=version2.split('.')
        if(len(lst1)>len(lst2)):
            for i in range(len(lst1)-len(lst2)):
                lst2.append('0')
        if(len(lst2)>len(lst1)):
            for i in range(len(lst2)-len(lst1)):
                lst1.append('0')
        for i in range(len(lst1)):
            if(int(lst1[i])>int(lst2[i])):
                return 1
            if(int(lst1[i])<int(lst2[i])):
                return -1
        return 0       