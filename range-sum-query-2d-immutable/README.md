<h2>304. Range Sum Query 2D - Immutable</h2><h3>Medium</h3><hr><div><p>Given a 2D matrix <i>matrix</i>, find the sum of the elements inside the rectangle defined by its upper left corner (<i>row</i>1, <i>col</i>1) and lower right corner (<i>row</i>2, <i>col</i>2).</p>

<p>
<img src="/static/images/courses/range_sum_query_2d.png" border="0" alt="Range Sum Query 2D"><br>
<small>The above rectangle (with the red border) is defined by (row1, col1) = <b>(2, 1)</b> and (row2, col2) = <b>(4, 3)</b>, which contains sum = <b>8</b>.</small>
</p>

<p><b>Example:</b><br>
</p><pre>Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -&gt; 8
sumRegion(1, 1, 2, 2) -&gt; 11
sumRegion(1, 2, 2, 4) -&gt; 12
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>You may assume that the matrix does not change.</li>
<li>There are many calls to <i>sumRegion</i> function.</li>
<li>You may assume that <i>row</i>1 ≤ <i>row</i>2 and <i>col</i>1 ≤ <i>col</i>2.</li>
</ol>
<p></p></div>