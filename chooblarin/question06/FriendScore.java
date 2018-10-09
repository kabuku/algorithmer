public class FriendScore {
  public int highestScore(String[] friends) {
    int n = friends.length;
    int maxCount = 0;
    int[][] mat = adjacencyMatrix(friends);
    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        }

        count += mat[i][j];
        if (mat[i][j] == 1) {
          for (int k = 0; k < n; k++) {
            if (i == k) {
              continue;
            }
            if (mat[i][k] == 0) {
              count += mat[k][j];
            }
          }
        }
      }
      maxCount = Math.max(maxCount, count);
    }
    return maxCount;
  }

  private int[][] adjacencyMatrix(String[] strings) {
    int ni = strings.length;
    int nj = strings.length == 0 ? 0 : strings[0].length();
    int[][] matrix = new int[ni][nj];
    for (int i = 0; i < ni; i++) {
      char[] chars = strings[i].toCharArray();
      for (int j = 0; j < nj; j++) {
        matrix[i][j] = chars[j] == 'Y' ? 1 : 0;
      }
    }
    return matrix;
  }
}
