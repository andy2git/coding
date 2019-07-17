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

// java 8 solution
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if(prerequisites == null || prerequisites.length == 0) return true;

        Map<Integer, List<Integer>> graph = new HashMap<>();
        Map<Integer, Integer> dMap = new HashMap<>();
        fillInGraphAndDegree(prerequisites, graph, dMap);

        Queue<Integer> queue = new ArrayDeque<>();
        for(int i = 0; i < numCourses; i++) {
            if(!dMap.containsKey(i)){
                queue.offer(i);
            }
        }

        int count = 0;
        while(!queue.isEmpty()) {
            Integer t = queue.poll();
            for(Integer x : graph.getOrDefault(t, Collections.emptyList())){
                Integer degree = dMap.merge(x, -1, Integer::sum);
                if(degree == 0) queue.offer(x);
            }
            count++;

        }

        return count == numCourses;
    }

    private void fillInGraphAndDegree(int[][] edges, Map<Integer, List<Integer>> graph, Map<Integer, Integer> dMap) {
        for(int[] edge: edges) {
            graph.merge(edge[1], new ArrayList<>(Collections.singleton(edge[0])), (x, y) ->  {
                x.add(edge[0]);
                return x;
            });
            dMap.merge(edge[0], 1, Integer::sum);
        }
    }
}
