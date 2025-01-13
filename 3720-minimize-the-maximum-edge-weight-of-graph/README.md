<h2><a href="https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph">Minimize the Maximum Edge Weight of Graph</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given two integers, <code>n</code> and <code>threshold</code>, as well as a <strong>directed</strong> weighted graph of <code>n</code> nodes numbered from 0 to <code>n - 1</code>. The graph is represented by a <strong>2D</strong> integer array <code>edges</code>, where <code>edges[i] = [A<sub>i</sub>, B<sub>i</sub>, W<sub>i</sub>]</code> indicates that there is an edge going from node <code>A<sub>i</sub></code> to node <code>B<sub>i</sub></code> with weight <code>W<sub>i</sub></code>.</p>

<p>You have to remove some edges from this graph (possibly <strong>none</strong>), so that it satisfies the following conditions:</p>

<ul>
	<li>Node 0 must be reachable from all other nodes.</li>
	<li>The <strong>maximum</strong> edge weight in the resulting graph is <strong>minimized</strong>.</li>
	<li>Each node has <strong>at most</strong> <code>threshold</code> outgoing edges.</li>
</ul>

<p>Return the <strong>minimum</strong> possible value of the <strong>maximum</strong> edge weight after removing the necessary edges. If it is impossible for all conditions to be satisfied, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/09/s-1.png" style="width: 300px; height: 233px;" /></p>

<p>Remove the edge <code>2 -&gt; 0</code>. The maximum weight among the remaining edges is 1.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, edges = [[0,1,1],[0,2,2],[0,3,1],[0,4,1],[1,2,1],[1,4,1]], threshold = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong>&nbsp;</p>

<p>It is impossible to reach node 0 from node 2.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[3,4,2],[4,0,1]], threshold = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong>&nbsp;</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/09/s2-1.png" style="width: 300px; height: 267px;" /></p>

<p>Remove the edges <code>1 -&gt; 3</code> and <code>1 -&gt; 4</code>. The maximum weight among the remaining edges is 2.</p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[4,0,1]], threshold = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= threshold &lt;= n - 1</code></li>
	<li><code>1 &lt;= edges.length &lt;= min(10<sup>5</sup>, n * (n - 1) / 2).</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= A<sub>i</sub>, B<sub>i</sub> &lt; n</code></li>
	<li><code>A<sub>i</sub> != B<sub>i</sub></code></li>
	<li><code>1 &lt;= W<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>There <strong>may be</strong> multiple edges between a pair of nodes, but they must have unique weights.</li>
</ul>
