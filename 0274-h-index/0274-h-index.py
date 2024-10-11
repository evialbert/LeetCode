class Solution:
    def hIndex(self, citations: List[int]) -> int:
        h = 0
        for paper_citations in reversed(sorted(citations)):
            if paper_citations > h:
                h += 1
            else:
                return h

        return h