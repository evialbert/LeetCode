<h2><a href="https://leetcode.com/problems/count-the-number-of-winning-sequences/">3320. Count The Number of Winning Sequences</a></h2><h3>Hard</h3><hr><div><p>Alice and Bob are playing a fantasy battle game consisting of <code>n</code> rounds where they summon one of three magical creatures each round: a Fire Dragon, a Water Serpent, or an Earth Golem. In each round, players <strong>simultaneously</strong> summon their creature and are awarded points as follows:</p>

<ul>
	<li>If one player summons a Fire Dragon and the other summons an Earth Golem, the player who summoned the <strong>Fire Dragon</strong> is awarded a point.</li>
	<li>If one player summons a Water Serpent and the other summons a Fire Dragon, the player who summoned the <strong>Water Serpent</strong> is awarded a point.</li>
	<li>If one player summons an Earth Golem and the other summons a Water Serpent, the player who summoned the <strong>Earth Golem</strong> is awarded a point.</li>
	<li>If both players summon the same creature, no player is awarded a point.</li>
</ul>

<p>You are given a string <code>s</code> consisting of <code>n</code> characters <code>'F'</code>, <code>'W'</code>, and <code>'E'</code>, representing the sequence of creatures Alice will summon in each round:</p>

<ul>
	<li>If <code>s[i] == 'F'</code>, Alice summons a Fire Dragon.</li>
	<li>If <code>s[i] == 'W'</code>, Alice summons a Water Serpent.</li>
	<li>If <code>s[i] == 'E'</code>, Alice summons an Earth Golem.</li>
</ul>

<p>Bob’s sequence of moves is unknown, but it is guaranteed that Bob will never summon the same creature in two consecutive rounds. Bob <em>beats</em> Alice if the total number of points awarded to Bob after <code>n</code> rounds is <strong>strictly greater</strong> than the points awarded to Alice.</p>

<p>Return the number of distinct sequences Bob can use to beat Alice.</p>

<p>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "FFF"</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>Bob can beat Alice by making one of the following sequences of moves: <code>"WFW"</code>, <code>"FWF"</code>, or <code>"WEW"</code>. Note that other winning sequences like <code>"WWE"</code> or <code>"EWW"</code> are invalid since Bob cannot make the same move twice in a row.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "FWEFW"</span></p>

<p><strong>Output:</strong> <span class="example-io">18</span></p>

<p><strong>Explanation:</strong></p>

<p><w>Bob can beat Alice by making one of the following sequences of moves: <code>"FWFWF"</code>, <code>"FWFWE"</code>, <code>"FWEFE"</code>, <code>"FWEWE"</code>, <code>"FEFWF"</code>, <code>"FEFWE"</code>, <code>"FEFEW"</code>, <code>"FEWFE"</code>, <code>"WFEFE"</code>, <code>"WFEWE"</code>, <code>"WEFWF"</code>, <code>"WEFWE"</code>, <code>"WEFEF"</code>, <code>"WEFEW"</code>, <code>"WEWFW"</code>, <code>"WEWFE"</code>, <code>"EWFWE"</code>, or <code>"EWEWE"</code>.</w></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is one of <code>'F'</code>, <code>'W'</code>, or <code>'E'</code>.</li>
</ul>
</div>