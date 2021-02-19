class Solution(object):

    def numDistinct(self, s, t):

        """

        :type s: str

        :type t: str

        :rtype: int

        """

 

        cnt=[0]*len(t)

 

        for si,sc in enumerate(s):

            lastc=""

            rep=0

            for ti in xrange(len(t)-1,-1,-1):

                tc=t[ti]

                if tc==sc:

                    if ti==0:

                        cnt[ti]+=1

                    else:

                        cnt[ti]+=cnt[ti-1]

        return  cnt[-1]