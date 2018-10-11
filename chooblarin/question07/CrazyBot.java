import java.util.HashSet;

public class CrazyBot {
  private HashSet<String> hashSet = new HashSet();

  public double getProbability(int n, int east, int west, int south, int north) {
    double[] probs = new double[] { east / 100.0, west / 100.0, south / 100.0, north / 100.0 };
    return step(n, 0, 0, probs);
  }

  private double step(int n, int x, int y, double[] probs) {
    if (n < 0) {
      return 1.0;
    }

    String pos = x + "," + y;
    if (hashSet.contains(pos)) {
      return 0.0;
    }

    hashSet.add(pos);

    double result = 0.0;
    result += step(n - 1, x + 1, y, probs) * probs[0];
    result += step(n - 1, x - 1, y, probs) * probs[1];
    result += step(n - 1, x, y - 1, probs) * probs[2];
    result += step(n - 1, x, y + 1, probs) * probs[3];

    hashSet.remove(pos);

    return result;
  }
}
