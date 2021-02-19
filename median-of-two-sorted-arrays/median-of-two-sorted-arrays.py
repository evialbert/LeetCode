class Solution:

    # @return a float
    def findMedianSortedArrays(self, A, B):

        len_a = len(A)
        len_b = len(B)
        len_total = len_a + len_b
        if 0 == len_total:
            return ''
        if 0 == len_a and 1 == len_b:
            return B[0]
        if 1 == len_a and 0 == len_b:
            return A[0]
        if 1 == len_a and 1 == len_b:
            return float(A[0] + B[0]) / 2

        median_index = len_total / 2
        is_odd = (1 == len_total % 2)

        index_a = -1
        index_b = -1
        median_num = 0
        for i in range(0, median_index + 1):
            if index_a + 1 < len_a and (index_b + 1 >= len_b or A[index_a + 1] <= B[index_b + 1]):
                index_a += 1
                last_median_num = median_num
                median_num = A[index_a]
            else:
                index_b += 1
                last_median_num = median_num
                median_num = B[index_b]

        if is_odd:
            median_num = median_num
        else:
            median_num = float(last_median_num + median_num) / 2

        return median_num


        