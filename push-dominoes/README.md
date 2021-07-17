<h2>838. Push Dominoes</h2><h3>Medium</h3><hr><div><p>There are<font face="monospace">&nbsp;<code>N</code></font> dominoes in a line, and we place each domino vertically upright.</p>

<p>In the beginning, we simultaneously push&nbsp;some of the dominoes either to the left or to the right.</p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png" style="height: 160px;"></p>

<p>After each second, each domino that is falling to the left pushes the adjacent domino on the left.</p>

<p>Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.</p>

<p>When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.</p>

<p>For the purposes of this question, we will consider that a falling domino&nbsp;expends no additional force to a falling or already fallen domino.</p>

<p>Given a string "S" representing the initial state.&nbsp;<code>S[i] = 'L'</code>, if the i-th domino has been pushed to the left; <code>S[i] = 'R'</code>, if the i-th domino has been pushed to the right; <code>S[i] = '.'</code>,&nbsp;if the <code>i</code>-th domino has not been pushed.</p>

<p>Return a string representing the final state.&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>".L.R...LR..L.."
<strong>Output: </strong>"LL.RR.LLRRLL.."
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>"RR.L"
<strong>Output: </strong>"RR.L"
<strong>Explanation: </strong>The first domino expends no additional force on the second domino.
</pre>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= N&nbsp;&lt;= 10^5</code></li>
	<li>String&nbsp;<code>dominoes</code> contains only&nbsp;<code>'L</code>', <code>'R'</code> and <code>'.'</code></li>
</ol>
</div>