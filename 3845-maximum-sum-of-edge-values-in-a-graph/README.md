<h2><a href="https://leetcode.com/problems/maximum-sum-of-edge-values-in-a-graph">Maximum Sum of Edge Values in a Graph</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given an <strong>undirected connected</strong> graph of <code>n</code> nodes, numbered from <code>0</code> to <code>n - 1</code>. Each node is connected to <strong>at most</strong> 2 other nodes.</p>

<p>The graph consists of <code>m</code> edges, represented by a 2D array <code>edges</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>.</p>

<p data-end="502" data-start="345">You have to assign a <strong>unique</strong> value from <code data-end="391" data-start="388">1</code> to <code data-end="398" data-start="395">n</code> to each node. The value of an edge will be the <strong>product</strong> of the values assigned to the two nodes it connects.</p>

<p data-end="502" data-start="345">Your score is the sum of the values of all edges in the graph.</p>

<p>Return the <strong>maximum</strong> score you can achieve.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2025/05/12/screenshot-from-2025-05-13-01-27-52.png" style="width: 411px; height: 123px;" />
<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4, edges =&nbsp;</span>[[0,1],[1,2],[2,3]]</p>

<p><strong>Output:</strong> 23</p>

<p><strong>Explanation:</strong></p>

<p>The diagram above illustrates an optimal assignment of values to nodes. The sum of the values of the edges is: <code>(1 * 3) + (3 * 4) + (4 * 2) = 23</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2025/03/23/graphproblemex2drawio.png" style="width: 220px; height: 255px;" />
<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 6, edges = [[0,3],[4,5],[2,0],[1,3],[2,4],[1,5]]</span></p>

<p><strong>Output:</strong> <span class="example-io">82</span></p>

<p><strong>Explanation:</strong></p>

<p>The diagram above illustrates an optimal assignment of values to nodes. The sum of the values of the edges is: <code>(1 * 2) + (2 * 4) + (4 * 6) + (6 * 5) + (5 * 3) + (3 * 1) = 82</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>m == edges.length</code></li>
	<li><code>1 &lt;= m &lt;= n</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>There are no repeated edges.</li>
	<li>The graph is connected.</li>
	<li>Each node is connected to at most 2 other nodes.</li>
</ul>
