<h2>762. Prime Number of Set Bits in Binary Representation</h2><h3>Easy</h3><hr><div><p>
Given two integers <code>L</code> and <code>R</code>, find the count of numbers in the range <code>[L, R]</code> (inclusive) having a prime number of set bits in their binary representation.
</p><p>
(Recall that the number of set bits an integer has is the number of <code>1</code>s present when written in binary.  For example, <code>21</code> written in binary is <code>10101</code> which has 3 set bits.  Also, 1 is not a prime.)
</p><p>

</p><p><b>Example 1:</b><br></p><pre><b>Input:</b> L = 6, R = 10
<b>Output:</b> 4
<b>Explanation:</b>
6 -&gt; 110 (2 set bits, 2 is prime)
7 -&gt; 111 (3 set bits, 3 is prime)
9 -&gt; 1001 (2 set bits , 2 is prime)
10-&gt;1010 (2 set bits , 2 is prime)
</pre><p></p>

<p><b>Example 2:</b><br></p><pre><b>Input:</b> L = 10, R = 15
<b>Output:</b> 5
<b>Explanation:</b>
10 -&gt; 1010 (2 set bits, 2 is prime)
11 -&gt; 1011 (3 set bits, 3 is prime)
12 -&gt; 1100 (2 set bits, 2 is prime)
13 -&gt; 1101 (3 set bits, 3 is prime)
14 -&gt; 1110 (3 set bits, 3 is prime)
15 -&gt; 1111 (4 set bits, 4 is not prime)
</pre><p></p>

<p><b>Note:</b><br></p><ol>
<li><code>L, R</code> will be integers <code>L &lt;= R</code> in the range <code>[1, 10^6]</code>.</li>
<li><code>R - L</code> will be at most 10000.</li>
</ol><p></p></div>