import java.util.ArrayList;
import java.util.Collections;

public class ThePalindrome {
  public int find(String s) {
    char[] chars = s.toCharArray();
    int lastIndex = chars.length - 1;
    String forwordPart = "";
    String backwordPart = "";
    ArrayList<Integer> muchedIndices = new ArrayList<>();
    for (int i = 0; i < chars.length; i++) {
      forwordPart = chars[lastIndex - i] + forwordPart;
      backwordPart = backwordPart + chars[lastIndex - i];
      if (forwordPart.equals(backwordPart)) {
        muchedIndices.add(i);
      }
    }
    int maxMuchedIndex = muchedIndices.isEmpty() ? 0 : Collections.max(muchedIndices);
    return lastIndex - maxMuchedIndex + chars.length;
  }
}
