class Solution(object):

    def compareVersion(self, version1, version2):

        v1 = version1.split('.')

        v2 = version2.split('.')

        

        sum1 = sum([int(value) * (10 ** -key) for key, value in enumerate(v1)])

        sum2 = sum([int(value) * (10 ** -key) for key, value in enumerate(v2)])

        

        if sum1 > sum2:

            return 1

        elif sum1 < sum2:

            return -1

        

        return 0

        
        