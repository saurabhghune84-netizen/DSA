
# Kruskal's Algorithm to find Minimum Spanning Tree

V = 6

# Edges: (source, destination, distance)
edges = [
    (0, 1, 10),
    (0, 2, 20),
    (1, 3, 15),
    (1, 4, 30),
    (2, 3, 5),
    (2, 5, 25),
    (3, 4, 10),
    (4, 5, 12)
]

# Department names
departments = [
    "Computer Science",
    "IT Department",
    "Mechanical",
    "Electrical",
    "Library",
    "Administration"
]

parent = list(range(V))


# Find operation
def find(i):
    if parent[i] != i:
        parent[i] = find(parent[i])
    return parent[i]


# Union operation
def union(x, y):
    parent[x] = y


# Kruskal's Algorithm
def kruskal():
    global parent
    parent = list(range(V))

    edges.sort(key=lambda x: x[2])

    total = 0
    count = 0

    print("Minimum Spanning Tree:")

    for u, v, weight in edges:

        x = find(u)
        y = find(v)

        if x != y:
            print(departments[u], "-", departments[v],
                  ":", weight, "meters")

            union(x, y)

            total += weight
            count += 1

            if count == V - 1:
                break

    print("\nTotal Minimum Distance:", total, "meters")


# Main program
kruskal()
