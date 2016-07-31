class Solution {
    
    private static class Pair<A, B> {
        A first;
        B second;
    
        Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    
        public static <A, B> Pair of(A first, B second) {
            return new Pair<>(first, second);
        }
    }

    public int countOfAirplanes(List<Interval> airplanes) {
        SortedMultiset<Pair<Integer, Integer>> sortedSet =
                TreeMultiset.create(new Comparator<Pair<Integer, Integer>>() {
                    @Override
                    public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
                        return o1.first.compareTo(o2.first);
                    }
                });

        for (Interval itv : airplanes) {
            sortedSet.add(Pair.of(itv.start, 1));
            sortedSet.add(Pair.of(itv.end, -1));
        }

        return maxSubSum(sortedSet);
    }

    private int maxSubSum(SortedMultiset<Pair<Integer, Integer>> collection) {
        int maxSum = 0;
        int[] t = new int[collection.size() + 1];
        int i = 1;
        for (Pair<Integer, Integer> x : collection) {
            t[i] = Math.max(t[i - 1] + x.second, x.second);
            if (t[i] > maxSum) {
                maxSum = t[i];
            }
            i++;
        }
        return maxSum;
    }

    @Test
    public void testAirPlanes() {
        List<Interval> airplanes = Lists.newArrayList(new Interval(1, 4), new Interval(1, 4), new Interval(1, 4));
        System.out.println(countOfAirplanes(airplanes));
    }
}
