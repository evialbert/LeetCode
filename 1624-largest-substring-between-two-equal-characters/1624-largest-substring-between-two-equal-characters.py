class Solution:
	def maxLengthBetweenEqualCharacters(self, s: str) -> int:
		d = {}
		maxi = 0
		flag = 0

		for i in range(len(s)):
			if len(d) == 0:
				d[s[i]] = i
			else:
				if s[i] in d:
					flag = 1
					temp = i - d[s[i]] - 1
					if temp > maxi:
						maxi = temp
				else:
					d[s[i]] = i

		if flag == 0:
			return -1
		return maxi