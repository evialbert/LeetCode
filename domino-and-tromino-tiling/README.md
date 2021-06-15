<h2>790. Domino and Tromino Tiling</h2><h3>Medium</h3><hr><div><p>We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.</p>

<pre>XX  &lt;- domino

XX  &lt;- "L" tromino
X
</pre>

<p>Given <code>n</code>, how many ways are there to tile a <code>2 x n</code> board? <strong>Return your answer modulo </strong><code>10<sup>9</sup> + 7</code>.</p>

<p>(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)</p>

<pre><strong>Example:</strong>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>n</code> will be in range <code>[1, 1000]</code>.</li>
</ul>

<p>&nbsp;</p>
</div>