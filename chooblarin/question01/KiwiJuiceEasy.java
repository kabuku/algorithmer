public class KiwiJuiceEasy {
    public int[] thePouring(int[] capacities, int[] bottles, int[] fromId, int[] toId) {
        for (int i = 0; i < fromId.length; i++) {
            int from = fromId[i];
            int to = toId[i];
            if (capacities[to] < bottles[to] + bottles[from]) {
                int poured = Math.min(capacities[to] - bottles[to], bottles[from]);
                bottles[from] -= poured;
                bottles[to] += poured;
            } else {
                bottles[to] += bottles[from];
                bottles[from] = 0;
            }
        }
        return bottles;
    }
}
