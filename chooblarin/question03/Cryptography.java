public class Cryptography {
    public long encrypt(int[] numbers) {
        long m = 0;
        for (int i = 0; i < numbers.length; i++) {
            long p = 1;
            for (int j = 0; j < numbers.length; j++) {
                if (i == j) {
                    p *= numbers[j] + 1;
                } else {
                    p *= numbers[j];
                }
            }
            m = Math.max(m, p);
        }
        return m;
    }
}
