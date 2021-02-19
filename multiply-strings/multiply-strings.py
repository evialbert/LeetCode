class Solution:
	def multiply(self, num1: str, num2: str) -> str:
		s2i={'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}
		i2s={value:key for key, value in s2i.items()}

		def str_int(num: str) -> int:
			ans=0
			while len(num)>0:
				ans=ans*10+s2i[num[0]]
				num=num[1:]
			return ans

		def int_str(num: int) -> str:
			ans=''
			if num==0: return '0'
			while num>0:
				ans = i2s[num%10] + ans
				num = num//10
			return ans

		return int_str(str_int(num1) * str_int(num2))