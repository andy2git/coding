class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        for(int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }

        Map<Integer, Integer> dMap = fillinDegreeAndGraph(prerequisites, graph);

        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < numCourses; i++) {
            if (!dMap.containsKey(i)) {
                queue.offer(i);
            }
        }

        int cnt = 0;
        while (!queue.isEmpty()) {
            int n = queue.poll();
            cnt++;
            for (int x : graph.get(n)) {
                dMap.put(x, dMap.get(x) - 1);
                if (dMap.get(x) == 0) {
                    queue.offer(x);
                }
            }
        }

        return cnt == numCourses;
    }

    private Map<Integer, Integer> fillinDegreeAndGraph(int[][] edges, List<List<Integer>> graph) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int[] x : edges) {
            graph.get(x[1]).add(x[0]);
            map.put(x[0], map.getOrDefault(x[0], 0) + 1);
        }
        return map;
    }
}
