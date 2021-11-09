<h2>1307. Verbal Arithmetic Puzzle</h2><h3>Hard</h3><hr><div><p>Given an equation, represented by <code>words</code> on left side and the <code>result</code> on right side.</p>

<p>You need to check if the equation is solvable&nbsp;under the following rules:</p>

<ul>
	<li>Each character is decoded as one digit (0 - 9).</li>
	<li>Every pair of different characters they must map to different digits.</li>
	<li>Each <code>words[i]</code> and <code>result</code>&nbsp;are decoded as one number <strong>without</strong> leading zeros.</li>
	<li>Sum of numbers on left side (<code>words</code>) will equal to the number on right side (<code>result</code>).&nbsp;</li>
</ul>

<p>Return <code>True</code>&nbsp;if the equation is solvable otherwise&nbsp;return&nbsp;<code>False</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["SEND","MORE"], result = "MONEY"
<strong>Output:</strong> true
<strong>Explanation:</strong> Map 'S'-&gt; 9, 'E'-&gt;5, 'N'-&gt;6, 'D'-&gt;7, 'M'-&gt;1, 'O'-&gt;0, 'R'-&gt;8, 'Y'-&gt;'2'
Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
<strong>Output:</strong> true
<strong>Explanation:</strong> Map 'S'-&gt; 6, 'I'-&gt;5, 'X'-&gt;0, 'E'-&gt;8, 'V'-&gt;7, 'N'-&gt;2, 'T'-&gt;1, 'W'-&gt;'3', 'Y'-&gt;4
Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["THIS","IS","TOO"], result = "FUNNY"
<strong>Output:</strong> true
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> words = ["LEET","CODE"], result = "POINT"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= words.length &lt;= 5</code></li>
	<li><code>1 &lt;= words[i].length, result.length &lt;= 7</code></li>
	<li><code>words[i], result</code> contain only uppercase English letters.</li>
	<li>The number of different characters used in the expression is at most <code>10</code>.</li>
</ul>
</div>