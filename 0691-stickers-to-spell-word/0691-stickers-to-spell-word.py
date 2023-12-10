class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        
        # use the given sticker to remove elements from target. whatever is left of target is returned.
        def match(sticker, target):
            used = set()
            for i, s in enumerate(sticker):
                for j, t in enumerate(target):
                    if s == t and j not in used:
                        used.add(j)
                        break
            res = ""
            for j, t in enumerate(target):
                if j not in used:
                    res += t
            return res

        @cache
        def dp(target):
            if not target:
                return 0
            res = []
            # try each sticker
            for sticker in stickers:
                new_target = match(sticker, target)
                if len(target) > len(new_target):
                    sub = dp(new_target)
                    if sub != -1:
                        res.append(1 + sub)

            if res:
                return min(res)
            else:
                return -1

        return dp(target)