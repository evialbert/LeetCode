<h2><a href="https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/">3106. Lexicographically Smallest String After Operations With Constraint</a></h2><h3>Medium</h3><hr><div><p>You are given a string <code>s</code> and an integer <code>k</code>.</p>

<p>Define a function <code>distance(s<sub>1</sub>, s<sub>2</sub>)</code> between two strings <code>s<sub>1</sub></code> and <code>s<sub>2</sub></code> of the same length <code>n</code> as:</p>

<ul>
	<li>The<strong> sum</strong> of the <strong>minimum distance</strong> between <code>s<sub>1</sub>[i]</code> and <code>s<sub>2</sub>[i]</code> when the characters from <code>'a'</code> to <code>'z'</code> are placed in a <strong>cyclic</strong> order, for all <code>i</code> in the range <code>[0, n - 1]</code>.</li>
</ul>

<p>For example, <code>distance("ab", "cd") == 4</code>, and <code>distance("a", "z") == 1</code>.</p>

<p>You can <strong>change</strong> any letter of <code>s</code> to <strong>any</strong> other lowercase English letter, <strong>any</strong> number of times.</p>

<p>Return a string denoting the <strong><span data-keyword="lexicographically-smaller-string">lexicographically smallest</span></strong> string <code>t</code> you can get after some changes, such that <code>distance(s, t) &lt;= k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "zbbz", k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">"aaaz"</span></p>

<p><strong>Explanation:</strong></p>

<p>Change <code>s</code> to <code>"aaaz"</code>. The distance between <code>"zbbz"</code> and <code>"aaaz"</code> is equal to <code>k = 3</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "xaxcd", k = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">"aawcd"</span></p>

<p><strong>Explanation:</strong></p>

<p>The distance between "xaxcd" and "aawcd" is equal to k = 4.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "lol", k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">"lol"</span></p>

<p><strong>Explanation:</strong></p>

<p>It's impossible to change any character as <code>k = 0</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2000</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
</div>