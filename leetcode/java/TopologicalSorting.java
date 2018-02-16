private static class DirectedGraphNode {
        int label;
        List<DirectedGraphNode> neighbors;

        DirectedGraphNode(int x) {
            label = x;
            neighbors = new ArrayList<>();
        }
    }

public class Solution {
    public List<DirectedGraphNode> topSort(List<DirectedGraphNode> graph) {
        Map<DirectedGraphNode, Integer> dMap = fillDegreeMap(graph);

        List<DirectedGraphNode> result = new ArrayList<>();
        Queue<DirectedGraphNode> queue = new ArrayDeque<>();
        for(DirectedGraphNode x : graph) {
            if(!dMap.containsKey(x)) {
                queue.offer(x);
            }
        }

        while(!queue.isEmpty()) {
            DirectedGraphNode n = queue.poll();
            result.add(n);
            for(DirectedGraphNode x : n.neighbors) {
                dMap.put(x, dMap.get(x)-1);
                if(dMap.get(x) == 0) {
                    queue.offer(x);
                }
            }
        }
        return result;
    }

    private Map<DirectedGraphNode, Integer> fillDegreeMap(List<DirectedGraphNode> graph) {
        Map<DirectedGraphNode, Integer> map = new HashMap<>();
        for (DirectedGraphNode x : graph) {
            for (DirectedGraphNode y : x.neighbors) {
                map.put(y, map.getOrDefault(y, 0) + 1);
            }
        }
        return map;
    }
}