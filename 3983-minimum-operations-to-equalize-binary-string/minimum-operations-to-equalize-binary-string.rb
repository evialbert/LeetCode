# @param {String} s
# @param {Integer} k
# @return {Integer}
def min_operations(s, k)    
  n = s.size; z = s.count('0'); o = n - z
  return 0 if z == 0
  (1..n).detect { |i| (i*k - z).even? && (i*k).between?(z, n*i - (i.odd? ? o:z)) } || -1
end