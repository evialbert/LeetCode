<h2><a href="https://leetcode.com/problems/minimum-moves-to-reach-target-in-grid">Minimum Moves to Reach Target in Grid</a></h2> <img src='https://img.shields.io/badge/Difficulty-Hard-red' alt='Difficulty: Hard' /><hr><p>You are given four integers <code>sx</code>, <code>sy</code>, <code>tx</code>, and <code>ty</code>, representing two points <code>(sx, sy)</code> and <code>(tx, ty)</code> on an infinitely large 2D grid.</p>

<p>You start at <code>(sx, sy)</code>.</p>

<p>At any point <code>(x, y)</code>, define <code>m = max(x, y)</code>. You can either:</p>

<ul>
	<li>Move to <code>(x + m, y)</code>, or</li>
	<li>Move to <code>(x, y + m)</code>.</li>
</ul>

<p>Return the <strong>minimum</strong> number of moves required to reach <code>(tx, ty)</code>. If it is impossible to reach the target, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">sx = 1, sy = 2, tx = 5, ty = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The optimal path is:</p>

<ul>
	<li>Move 1: <code>max(1, 2) = 2</code>. Increase the y-coordinate by 2, moving from <code>(1, 2)</code> to <code>(1, 2 + 2) = (1, 4)</code>.</li>
	<li>Move 2: <code>max(1, 4) = 4</code>. Increase the x-coordinate by 4, moving from <code>(1, 4)</code> to <code>(1 + 4, 4) = (5, 4)</code>.</li>
</ul>

<p>Thus, the minimum number of moves to reach <code>(5, 4)</code> is 2.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">sx = 0, sy = 1, tx = 2, ty = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>The optimal path is:</p>

<ul>
	<li>Move 1: <code>max(0, 1) = 1</code>. Increase the x-coordinate by 1, moving from <code>(0, 1)</code> to <code>(0 + 1, 1) = (1, 1)</code>.</li>
	<li>Move 2: <code>max(1, 1) = 1</code>. Increase the x-coordinate by 1, moving from <code>(1, 1)</code> to <code>(1 + 1, 1) = (2, 1)</code>.</li>
	<li>Move 3: <code>max(2, 1) = 2</code>. Increase the y-coordinate by 2, moving from <code>(2, 1)</code> to <code>(2, 1 + 2) = (2, 3)</code>.</li>
</ul>

<p>Thus, the minimum number of moves to reach <code>(2, 3)</code> is 3.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">sx = 1, sy = 1, tx = 2, ty = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">-1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>It is impossible to reach <code>(2, 2)</code> from <code>(1, 1)</code> using the allowed moves. Thus, the answer is -1.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= sx &lt;= tx &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= sy &lt;= ty &lt;= 10<sup>9</sup></code></li>
</ul>
