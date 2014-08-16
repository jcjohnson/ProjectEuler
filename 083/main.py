import csv

INPUT_FILE = 'matrix.txt'

def ShortestPath(edge_list, start, target):
  nodes = edge_list.keys()
  visited = dict.fromkeys(nodes, False)
  dist = dict.fromkeys(nodes, float('inf'))

  dist[start] = 0

  while True:
    # Find the closest unvisited node
    unvisited = [(node, dist[node]) for node in nodes if not visited[node]]
    cur = min(unvisited, key=lambda x: x[1])[0]

    if cur == target:
      return dist[cur]

    # Look at all neighbors of the current node
    for (neighbor, w) in edge_list[cur]:
      if not visited[neighbor]:
        dist[neighbor] = min(dist[neighbor], dist[cur] + w)

    visited[cur] = True

def BuildEdgeList(matrix):
  size = len(matrix)
  edge_list = {}
  for i in range(size):
    for j in range(size):
      edge_list[(i, j)] = []
      if i > 0:
        edge_list[(i, j)].append(((i - 1, j), matrix[i - 1][j]))
      if j > 0:
        edge_list[(i, j)].append(((i, j - 1), matrix[i][j - 1]))
      if i + 1 < size:
        edge_list[(i, j)].append(((i + 1, j), matrix[i + 1][j]))
      if j + 1 < size:
        edge_list[(i, j)].append(((i, j + 1), matrix[i][j + 1]))
  return edge_list

def Main():
  with open(INPUT_FILE, 'r') as f:
    reader = csv.reader(f)
    matrix = []
    for line in reader:
      line = [int(x) for x in line]
      matrix.append(line)

    edge_list = BuildEdgeList(matrix)
    
    size = len(matrix)    

    shortest = ShortestPath(edge_list, (0, 0), (size - 1, size - 1)) + matrix[0][0]
    print shortest

if __name__ == "__main__":
  Main()
