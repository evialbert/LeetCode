<h2>483. Smallest Good Base</h2><h3>Hard</h3><hr><div><p>For an integer n, we call k&gt;=2 a <i><b>good base</b></i> of n, if all digits of n base k are 1.</p>

<p>Now given a string representing n, you should return the smallest good base of n in string format.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> "13"
<b>Output:</b> "3"
<b>Explanation:</b> 13 base 3 is 111.
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> "4681"
<b>Output:</b> "8"
<b>Explanation:</b> 4681 base 8 is 11111.
</pre>

<p>&nbsp;</p>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> "1000000000000000000"
<b>Output:</b> "999999999999999999"
<b>Explanation:</b> 1000000000000000000 base 999999999999999999 is 11.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The range of n is [3, 10^18].</li>
	<li>The string representing n is always valid and will not have leading zeros.</li>
</ol>

<p>&nbsp;</p>
</div>