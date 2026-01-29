function minimumCost(
  source: string,
  target: string,
  original: string[],
  changed: string[],
  cost: number[]
): number {
  const n = source.length
  const INF = Number.MAX_SAFE_INTEGER
  const charCount = 26
  const charCodeOffset = 97 // ASCII code for 'a'

  // Initialize matrix with infinity
  const costMatrix = Array.from({ length: charCount }, () => Array(charCount).fill(INF))

  // Populate the cost matrix with direct transformation costs
  for (let i = 0; i < original.length; i++) {
    const from = original[i].charCodeAt(0) - charCodeOffset
    const to = changed[i].charCodeAt(0) - charCodeOffset
    costMatrix[from][to] = Math.min(costMatrix[from][to], cost[i])
  }

  // Set the diagonal to 0 (cost to convert a character to itself is 0)
  for (let i = 0; i < charCount; i++) {
    costMatrix[i][i] = 0
  }

  // Apply the Floyd-Warshall algorithm to find all-pairs shortest paths
  for (let k = 0; k < charCount; k++) {
    for (let i = 0; i < charCount; i++) {
      for (let j = 0; j < charCount; j++) {
        if (costMatrix[i][k] < INF && costMatrix[k][j] < INF) {
          costMatrix[i][j] = Math.min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j])
        }
      }
    }
  }

  // Calculate the total minimum cost to convert source to target
  let totalCost = 0
  for (let i = 0; i < n; i++) {
    const startChar = source[i].charCodeAt(0) - charCodeOffset
    const endChar = target[i].charCodeAt(0) - charCodeOffset
    const transformationCost = costMatrix[startChar][endChar]

    if (transformationCost === INF) return -1
    totalCost += transformationCost
  }

  return totalCost
}