<h2>1160. Find Words That Can Be Formed by Characters</h2><h3>Easy</h3><hr><div><p>You are given an array of strings&nbsp;<code>words</code>&nbsp;and a string&nbsp;<code>chars</code>.</p>

<p>A string is <em>good</em>&nbsp;if&nbsp;it can be formed by&nbsp;characters from <code>chars</code>&nbsp;(each character&nbsp;can only be used once).</p>

<p>Return the sum of lengths of all good strings in <code>words</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>words = <span id="example-input-1-1">["cat","bt","hat","tree"]</span>, chars = <span id="example-input-1-2">"atach"</span>
<strong>Output: </strong><span id="example-output-1">6</span>
<strong>Explanation: </strong>
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>words = <span id="example-input-2-1">["hello","world","leetcode"]</span>, chars = <span id="example-input-2-2">"welldonehoneyr"</span>
<strong>Output: </strong><span id="example-output-2">10</span>
<strong>Explanation: </strong>
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
</pre>

<p>&nbsp;</p>

<p><span><strong>Note:</strong></span></p>

<ol>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length, chars.length&nbsp;&lt;= 100</code></li>
	<li>All strings contain lowercase English letters only.</li>
</ol></div>