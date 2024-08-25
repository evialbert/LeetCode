<h2><a href="https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-ii/">3261. Count Substrings That Satisfy K-Constraint II</a></h2><h3>Hard</h3><hr><div><p>You are given a <strong>binary</strong> string <code>s</code> and an integer <code>k</code>.</p>

<p>You are also given a 2D integer array <code>queries</code>, where <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code>.</p>

<p>A <strong>binary string</strong> satisfies the <strong>k-constraint</strong> if <strong>either</strong> of the following conditions holds:</p>

<ul>
	<li>The number of <code>0</code>'s in the string is at most <code>k</code>.</li>
	<li>The number of <code>1</code>'s in the string is at most <code>k</code>.</li>
</ul>

<p>Return an integer array <code>answer</code>, where <code>answer[i]</code> is the number of <span data-keyword="substring-nonempty">substrings</span> of <code>s[l<sub>i</sub>..r<sub>i</sub>]</code> that satisfy the <strong>k-constraint</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "0001111", k = 2, queries = [[0,6]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[26]</span></p>

<p><strong>Explanation:</strong></p>

<p>For the query <code>[0, 6]</code>, all substrings of <code>s[0..6] = "0001111"</code> satisfy the k-constraint except for the substrings <code>s[0..5] = "000111"</code> and <code>s[0..6] = "0001111"</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]</span></p>

<p><strong>Output:</strong> <span class="example-io">[15,9,3]</span></p>

<p><strong>Explanation:</strong></p>

<p>The substrings of <code>s</code> with a length greater than 3 do not satisfy the k-constraint.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i] == [l<sub>i</sub>, r<sub>i</sub>]</code></li>
	<li><code>0 &lt;= l<sub>i</sub> &lt;= r<sub>i</sub> &lt; s.length</code></li>
	<li>All queries are distinct.</li>
</ul>
</div>