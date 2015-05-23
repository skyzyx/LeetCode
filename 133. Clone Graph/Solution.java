/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null)
            return null;
            
        LinkedList<UndirectedGraphNode> queue = new LinkedList<UndirectedGraphNode>();
        Map<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        
        UndirectedGraphNode newHead = new UndirectedGraphNode(node.label);
        queue.add(node);
        map.put(node, newHead);
        
        while (queue.size() > 0) {
            UndirectedGraphNode curr = queue.removeFirst(); // queue.get(0) and queue.getFirst() did NOT work, must remove.
            List<UndirectedGraphNode> currNeighbors = curr.neighbors; // Not LinkedList<UndirectedGraphNode> currNeighbors = curr.neighbors.
            
            for (UndirectedGraphNode temp: currNeighbors) {
                if (!map.containsKey(temp)) {
                    UndirectedGraphNode copy = new UndirectedGraphNode(temp.label);
                    map.put(temp, copy);
                    map.get(curr).neighbors.add(copy); // Clone all nodes.
                    queue.add(temp);
                } else {
                    map.get(curr).neighbors.add(map.get(temp));
                }
            }
        }
        return newHead;
    }
}
