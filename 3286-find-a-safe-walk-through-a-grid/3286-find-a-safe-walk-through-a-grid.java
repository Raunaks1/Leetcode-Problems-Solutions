class Solution {
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m = grid.size();
        int n = grid.get(0).size();
        int[][] directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[] {0, 0, health - grid.get(0).get(0)});
        int[][] visited = new int[m][n];
        for (int[] row : visited) {
            Arrays.fill(row, -1);
        }
        visited[0][0] = health - grid.get(0).get(0);

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int x = curr[0];
            int y = curr[1];
            int currHealth = curr[2];
            if (x == m - 1 && y == n - 1 && currHealth > 0) {
                return true;
            }

            for (int[] direction : directions) {
                int newX = x + direction[0];
                int newY = y + direction[1];
                if (newX >= 0 && newY >= 0 && newX < m && newY < n) {
                    int newHealth = currHealth - grid.get(newX).get(newY);
                    if (newHealth > 0 && newHealth > visited[newX][newY]) {
                        visited[newX][newY] = newHealth;
                        q.offer(new int[] {newX, newY, newHealth});
                    }
                }
            }
        }
        return false;
    }
}