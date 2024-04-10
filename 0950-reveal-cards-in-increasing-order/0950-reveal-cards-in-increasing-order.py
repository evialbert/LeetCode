class Solution:
	def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:

		result = [0 for _ in range(len(deck))]

		deck = sorted(deck)

		queue = deque()

		for index in range(len(deck)):

			queue.append(index)

		for card in deck:

			result[queue.popleft()] = card

			if queue:

				queue.append(queue.popleft())

		return result