<h2>880. Decoded String at Index</h2><h3>Medium</h3><hr><div><p>An encoded string <code>s</code> is given.&nbsp; To find and write the <em>decoded</em> string to a tape, the encoded string is read <strong>one character at a time</strong>&nbsp;and the following steps are taken:</p>

<ul>
	<li>If the character read is a letter, that letter is written onto the tape.</li>
	<li>If the character read is a digit (say <code>d</code>), the entire current tape is repeatedly written&nbsp;<code>d-1</code>&nbsp;more times in total.</li>
</ul>

<p>Now for some encoded string <code>s</code>, and an index <code>k</code>, find and return the <code>k</code>-th letter (1 indexed) in the decoded string.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>s = <span id="example-input-1-1">"leet2code3"</span>, k = <span id="example-input-1-2">10</span>
<strong>Output: </strong><span id="example-output-1">"o"</span>
<strong>Explanation: </strong>
The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>s = <span id="example-input-2-1">"ha22"</span>, k = <span id="example-input-2-2">5</span>
<strong>Output: </strong><span id="example-output-2">"h"</span>
<strong>Explanation: </strong>
The decoded string is "hahahaha".  The 5th letter is "h".
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>s = <span id="example-input-3-1">"a2345678999999999999999"</span>, k = <span id="example-input-3-2">1</span>
<strong>Output: </strong><span id="example-output-3">"a"</span>
<strong>Explanation: </strong>
The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".
</pre>
</div>
</div>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;will only contain lowercase letters and digits <code>2</code> through <code>9</code>.</li>
	<li><code>s</code>&nbsp;starts with a letter.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li>It's guaranteed that <code>k</code>&nbsp;is less than or equal to the length of the decoded string.</li>
	<li>The decoded string is guaranteed to have less than <code>2<sup>63</sup></code> letters.</li>
</ul>
</div>