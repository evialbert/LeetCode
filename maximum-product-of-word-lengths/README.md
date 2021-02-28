<h2>318. Maximum Product of Word Lengths</h2><h3>Medium</h3><hr><div><p>Given a string array <code>words</code>, find the maximum value of <code>length(word[i]) * length(word[j])</code> where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> <code>["abcw","baz","foo","bar","xtfn","abcdef"]</code>
<b>Output: </b><code>16 
<strong>Explanation: </strong></code>The two words can be <code>"abcw", "xtfn"</code><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">.</span></pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> <code>["a","ab","abc","d","cd","bcd","abcd"]</code>
<b>Output: </b><code>4 
<strong>Explanation: </strong></code>The two words can be <code>"ab", "cd"</code><span style="font-family: sans-serif, Arial, Verdana, &quot;Trebuchet MS&quot;;">.</span></pre>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> <code>["a","aa","aaa","aaaa"]</code>
<b>Output: </b><code>0 
<strong>Explanation: </strong></code>No such pair of words.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= words.length &lt;= 10^3</code></li>
	<li><code>0 &lt;= words[i].length &lt;= 10^3</code></li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>
</div>