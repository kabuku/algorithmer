import java.util.ArrayList;

public class InterestingDigits {
  public int[] digits(int base) {
    ArrayList<Integer> numbers = new ArrayList<>();
    for (int x = 2; x < base; x++) {
      if (check(x, base)) {
        numbers.add(x);
      }
    }
    return numbers.stream().mapToInt(i -> i).toArray();
  }

  private boolean check(int n, int base) {
    for (int i = 0; i < base; i++) {
      for (int j = 0; j < base; j++) {
        for (int k = 0; k < base; k++) {
          int v = i * base * base + j * base + k;
          // 倍数だけど3桁の和が倍数じゃない
          if (v % n == 0 && (i + j + k) % n != 0) {
            return false;
          }
        }
      }
    }
    return true;
  }
}
