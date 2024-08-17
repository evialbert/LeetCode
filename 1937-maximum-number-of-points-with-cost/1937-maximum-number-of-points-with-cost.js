/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    let m = points.length; 
    let n = points[0].length; 

    let dp = [...points[0]];

    for (let r = 1; r < m; r++) {
        let left_dp = [...dp];
        let right_dp = [...dp];
        for (let c = 1; c < n; c++) {
            left_dp[c] = Math.max(left_dp[c], left_dp[c - 1] - 1);
        }
        
        for (let c = n - 2; c >= 0; c--) {
            right_dp[c] = Math.max(right_dp[c], right_dp[c + 1] - 1);
        }
        
        for (let c = 0; c < n; c++) {
            dp[c] = points[r][c] + Math.max(left_dp[c], right_dp[c]);
        }
    }
    
    return Math.max(...dp);
};
