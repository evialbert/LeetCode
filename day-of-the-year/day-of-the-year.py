class Solution:
	def dayOfYear(self, date: str) -> int:
		d = {0:0, 1:31, 2:59, 3:90, 4:120, 5:151, 6:181, 7:212, 8:243, 9:273, 10:304, 11:334, 12:365}

		year, month, date = date.split('-')

		day = 0

		day = d[int(month)-1] + int(date)

		if  (int(year) % 400 == 0 or (int(year) % 4 == 0 and int(year) % 100 != 0)) and int(month) > 2:
			day += 1

		return day