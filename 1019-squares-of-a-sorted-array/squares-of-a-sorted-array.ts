function sortedSquares(A: number[]): number[] {
  return A.map((num) => num ** 2).sort((a, b) => a - b);
}