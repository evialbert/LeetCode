<h2><a href="https://leetcode.com/problems/longest-special-path">Longest Special Path</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given an undirected tree rooted at node <code>0</code> with <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code>, represented by a 2D array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, length<sub>i</sub>]</code> indicates an edge between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> with length <code>length<sub>i</sub></code>. You are also given an integer array <code>nums</code>, where <code>nums[i]</code> represents the value at node <code>i</code>.</p>

<p>A <b data-stringify-type="bold">special path</b> is defined as a <b data-stringify-type="bold">downward</b> path from an ancestor node to a descendant node such that all the values of the nodes in that path are <b data-stringify-type="bold">unique</b>.</p>

<p><strong>Note</strong> that a path may start and end at the same node.</p>

<p>Return an array <code data-stringify-type="code">result</code> of size 2, where <code>result[0]</code> is the <b data-stringify-type="bold">length</b> of the <strong>longest</strong> special path, and <code>result[1]</code> is the <b data-stringify-type="bold">minimum</b> number of nodes in all <i data-stringify-type="italic">possible</i> <strong>longest</strong> special paths.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], nums = [2,1,2,1,3,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[6,2]</span></p>

<p><strong>Explanation:</strong></p>

<h4>In the image below, nodes are colored by their corresponding values in <code>nums</code></h4>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/11/02/tree3.jpeg" style="width: 250px; height: 350px;" /></p>

<p>The longest special paths are <code>2 -&gt; 5</code> and <code>0 -&gt; 1 -&gt; 4</code>, both having a length of 6. The minimum number of nodes across all longest special paths is 2.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges = [[1,0,8]], nums = [2,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">[0,1]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/11/02/tree4.jpeg" style="width: 190px; height: 75px;" /></p>

<p>The longest special paths are <code>0</code> and <code>1</code>, both having a length of 0. The minimum number of nodes across all longest special paths is 1.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 5 * 10<sup><span style="font-size: 10.8333px;">4</span></sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= length<sub>i</sub> &lt;= 10<sup>3</sup></code></li>
	<li><code>nums.length == n</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 5 * 10<sup>4</sup></code></li>
	<li>The input is generated such that <code>edges</code> represents a valid tree.</li>
</ul>
