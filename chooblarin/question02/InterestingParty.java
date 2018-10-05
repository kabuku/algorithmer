import java.util.HashMap;
import java.util.Collections;

public class InterestingParty {
  public int bestInvitation(String[] first, String[] second) {
    HashMap<String, Integer> map = new HashMap<String, Integer>();

    for (int i = 0; i < first.length; i++) {
      String fst = first[i];
      int n = (map.get(fst) == null) ? 0 : map.get(fst);
      map.put(fst, n + 1);

      String snd = second[i];
      n = (map.get(snd) == null) ? 0 : map.get(snd);
      map.put(snd, n + 1);
    }
    return Collections.max(map.values());
  }
}
