
# Prim's Algorithm to find Minimum Spanning Tree

V = 6

# Adjacency Matrix
graph = [
    [0, 10, 20, 0, 0, 0],
    [10, 0, 0, 15, 30, 0],
    [20, 0, 0, 5, 0, 25],
    [0, 15, 5, 0, 10, 0],
    [0, 30, 0, 10, 0, 12],
    [0, 0, 25, 0, 12, 0]
]

departments = [
    "Computer Science",
    "IT Department",
    "Mechanical",
    "Electrical",
    "Library",
    "Administration"
]


def prim(graph):
    selected = [False] * V
    selected[0] = True

    total = 0
    count = 0

    print("Minimum Spanning Tree:")

    while count < V - 1:

        minimum = float('inf')
        x = -1
        y = -1

        for i in range(V):
            if selected[i]:
                for j in range(V):
                    if not selected[j] and graph[i][j] != 0:
                        if graph[i][j] < minimum:
                            minimum = graph[i][j]
                            x = i
                            y = j

        if x == -1:
            print("Graph is disconnected!")
            return

        print(departments[x], "-", departments[y],
              ":", minimum, "meters")

        total += minimum
        selected[y] = True
        count += 1

    print("\nTotal Minimum Distance:", total, "meters")


# Main program
prim(graph)
