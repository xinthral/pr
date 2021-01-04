class buildGraph():
    """ More info on graphs @ geeksforgeeks.org """
    def __init__(this):
        this.graph = defaultdict(list)
        this.edges = []

    def addEdge(this, u, v):
        this.graph[u].append(v)

    def generateEdges(this):
        for node in this.graph:
            for neighbour in this.graph[node]:
                this.edges.append((node, neighbour))

    def printEdges(this):
        print(this.edges)

    def findDFS(this, start, end, path=[]):
        path = path + [start]
        if (start == end):
            return(path)
        for node in this.graph[start]:
            if node not in path:
                newpath = this.findDFS(node, end, path)
                if newpath:
                    return(newpath)

    def findALL(this, start, end, path=[]):
        path = path + [start]
        if (start == end):
            return([path])
        paths = []
        for node in this.graph[start]:
            if node not in path:
                newpaths = this.findALL(node, end, path)
            for newpath in newpaths:
                paths.append(newpath)
        return(paths)

    def findShortest(this, start, end, path=[]):
        path = path + [start]
        if (start == end):
            return(path)
        shortest = None
        for node in this.graph[start]:
            if node not in path:
                newpath = this.findShortest(node, end, path)
                if newpath:
                    if not shortest or (len(newpath) < len(shortest)):
                        shortest = newpath
        return(shortest)
