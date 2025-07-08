class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort(key=lambda x: x[0])

        @cache
        def dp(idx, k):
            if k == 0 or idx >= len(events):
                return 0
            
            # Find next possible event that we can attend if we take this.
            # e.g. next event such that current_event[1] < next_event[0]
            next_event = bisect_right(events, events[idx][1], lo=idx + 1, key=lambda x: x[0])

            # Either we just ignore this event and move to next index or we attend this event 
            # and then continue with next available event.
            # dp(idx, k) = max(
            #       dp(idx + 1, k) -> ignore
            #       dp(next_event, k - 1) + events[idx][2] -> take
            # )
            return max(dp(idx + 1, k), events[idx][2] + dp(next_event, k - 1))
        
        return dp(0, k)
