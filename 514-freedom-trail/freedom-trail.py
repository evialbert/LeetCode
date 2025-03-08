class Solution:
    def get_steps(self, prev, cur, size):
        if cur >= prev:
            return min(cur - prev, prev - cur + size) + 1
        return min(prev - cur, cur - prev + size) + 1

    def findRotateSteps(self, ring: str, key: str) -> int:
        positions = defaultdict(list)
        for idx, char in enumerate(ring):
            positions[char].append(idx)

        prev_min_paths = {i: math.inf for i in positions[key[0]]}
        for idx in positions[key[0]]:
            steps = self.get_steps(0, idx, len(ring))
            prev_min_paths[idx] = min(prev_min_paths[idx], steps)

        for key_idx in range(1, len(key)):
            cur_min_paths = {i: math.inf for i in positions[key[key_idx]]}

            for prev_pos, min_path in prev_min_paths.items():
                for i in positions[key[key_idx]]:
                    steps = min_path + self.get_steps(prev_pos, i, len(ring))
                    cur_min_paths[i] = min(cur_min_paths[i], steps)

            prev_min_paths = cur_min_paths

        return min(prev_min_paths.values())