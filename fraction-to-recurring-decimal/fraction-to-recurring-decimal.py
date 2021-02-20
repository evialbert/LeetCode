class Solution:
	def fractionToDecimal(self, numerator: int, denominator: int) -> str:
		if denominator  == 0 : return ''
		if numerator == 0: return '0'

		# sign part
		sign = '' if numerator*denominator >= 0 else '-'

		# to non-negative vals
		numerator = abs(numerator)
		denominator = abs(denominator)

		# int part
		int_part = str(numerator//denominator)
		if numerator%denominator == 0:
			return sign + int_part

		# fractional part
		numerator= numerator % denominator
		frac = []
		cnt = 0
		visited = dict()
		while True:
			if numerator in visited: break # save numerator
			visited[numerator] = cnt
			numerator *= 10
			if numerator < denominator:
				frac.append('0')
			else:
				frac.append(str(numerator//denominator))
				numerator= numerator % denominator
			cnt += 1
		# repeat part
		tail = ''.join(frac[visited[numerator]:cnt])
		tail = '(' + tail + ')' if tail and tail != '0' else ''  
		# sign + int + dot + frac + repeat
		return sign + int_part + '.' + ''.join(frac[:visited[numerator]]) + tail