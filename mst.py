import heapq


class DisjointSets:
    """Finds quickly if two points belong to same set"""

    def __init__(self, totalNumOfSets):
        self.parent = [None] * totalNumOfSets
        self.rank = [None] * totalNumOfSets

    def makeSet(self, id):
        self.parent[id] = id
        self.rank[id] = 0

    def find(self, id):
        while id != self.parent[id]:
            id = self.parent[id]
        return id

    def findFast(self, id):
        """path compression heuristic. faster than find() in future calls to this method
        because we update the parent info"""
        if id != self.parent[id]:
            self.parent[id] = self.findFast(self.parent[id])
        return self.parent[id]

    def union(self, id1, id2):
        """union by rank heuristic. rank stores the height.
        update the id of the element that has smaller rank"""

        rootId1 = self.findFast(id1)
        rootId2 = self.findFast(id2)

        if rootId1 == rootId2:
            return

        if self.rank[rootId1] > self.rank[rootId2]:
            self.parent[rootId2] = rootId1
        else:
            self.parent[rootId1] = rootId2

            if self.rank[rootId1] == self.rank[rootId2]:
                self.rank[rootId2] += 1


class PriorityQueue:

    REMOVED = "REMOVED"

    def __init__(self):
        self.priorityQueue = []
        self.nodeInfo = {}

    def addNodeWithPriority(self, node, priority):
        """adds or updates the node in priority queue"""

        if node in self.nodeInfo:
            self.removeNode(node)

        entry = [priority, node]
        self.nodeInfo[node] = entry
        heapq.heappush(self.priorityQueue, entry)

    def removeNode(self, node):
        removedNode = self.nodeInfo.pop(node)
        removedNode[1] = PriorityQueue.REMOVED

    def extractMin(self):
        while not self.isEmpty():
            priority, node = heapq.heappop(self.priorityQueue)
            if node != PriorityQueue.REMOVED:
                del self.nodeInfo[node]
                return node

    def isEmpty(self):
        if self.priorityQueue:
            return False
        return True


def kruskal(adjacencyList, edgeWeights):
    """Finds minimum spanning tree i.e., minimum total edge length required to connect all nodes.
    Repeatedly adds next smallest edge which doesn't create cycle between nodes"""

    numberOfNodes = len(adjacencyList)
    solutionSet = set()
    totalSpan = 0
    disjointSet = DisjointSets(totalNumOfSets=numberOfNodes)

    id = 0
    nodeIdMap = {}
    for node in adjacencyList:
        nodeIdMap[node] = id
        disjointSet.makeSet(id)
        id += 1

    for edge in sorted(edgeWeights, key=edgeWeights.get):
        fromNode = edge[0]
        toNode = edge[1]
        if disjointSet.find(nodeIdMap[fromNode]) != disjointSet.find(nodeIdMap[toNode]):
            solutionSet.add(edge)
            totalSpan += edgeWeights[edge]
            disjointSet.union(nodeIdMap[fromNode], nodeIdMap[toNode])

    return solutionSet, totalSpan


def prim(adjacencyList, edgeWeights, nodeName):
    """Finds minimum spanning tree i.e., minimum total edge length required to connect all nodes
    Repeatedly adds nodes to the solution tree using the smallest edge"""

    cost = {}
    parent = {}
    nodesInSolTree = set()
    INFINITY = 10000

    for node in adjacencyList:
        cost[node] = INFINITY
        parent[node] = None
    cost[nodeName] = 0
    del parent[nodeName]

    priorityQueue = PriorityQueue()
    for node in adjacencyList:
        priorityQueue.addNodeWithPriority(node, cost[node])

    while not priorityQueue.isEmpty():

        fromNode = priorityQueue.extractMin()
        if fromNode == None:
            break

        nodesInSolTree.add(fromNode)
        for toNode in adjacencyList[fromNode]:
            if (toNode not in nodesInSolTree) and (
                cost[toNode] > edgeWeights[(fromNode, toNode)]
            ):
                cost[toNode] = edgeWeights[(fromNode, toNode)]
                parent[toNode] = fromNode
                priorityQueue.addNodeWithPriority(toNode, cost[toNode])

    totalSpan = sum(edgeWeights[(parent[toNode], toNode)] for toNode in parent)
    return parent, totalSpan


if __name__ == "__main__":

    adjacencyList = {
        "A": {"B", "D", "E"},
        "B": {"A", "C", "E", "F"},
        "C": {"B", "F"},
        "D": {"A", "E"},
        "E": {"A", "B", "D", "F"},
        "F": {"B", "C", "E"},
    }

    edgeWeights = {
        ("A", "B"): 4,
        ("A", "D"): 2,
        ("A", "E"): 1,
        ("B", "A"): 4,
        ("B", "C"): 8,
        ("B", "E"): 5,
        ("B", "F"): 6,
        ("C", "B"): 8,
        ("C", "F"): 1,
        ("D", "A"): 2,
        ("D", "E"): 3,
        ("E", "A"): 1,
        ("E", "B"): 5,
        ("E", "D"): 3,
        ("E", "F"): 9,
        ("F", "B"): 6,
        ("F", "C"): 1,
        ("F", "E"): 9,
    }

    solutionSet, totalSpan = kruskal(adjacencyList, edgeWeights)
    print("\nKruskal: Minimum Spanning Tree:", solutionSet)
    print("Kruskal: Total Span:", totalSpan)

    parentOfNodesPrim, totalSpanPrim = prim(adjacencyList, edgeWeights, "A")
    print("\nPrim: Minimum Spanning Tree:", parentOfNodesPrim)
    print("Prim: Total Span:", totalSpan)
