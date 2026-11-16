
class Node:
    def __init__(self, d):
        self.d = d
        self.l = self.r = None

def insert(t, x):
    if not t: return Node(x)
    if x < t.d: t.l = insert(t.l, x)
    elif x > t.d: t.r = insert(t.r, x)
    else: print("Duplicate Entry")
    return t

def search(t, x):
    if not t: return False
    if t.d == x: return True
    return search(t.l if x < t.d else t.r, x)

def delete(t, x):
    if not t: return None
    if x < t.d: t.l = delete(t.l, x)
    elif x > t.d: t.r = delete(t.r, x)
    else:
        if not t.l: return t.r
        if not t.r: return t.l
        p = t.r
        while p.l: p = p.l
        t.d = p.d
        t.r = delete(t.r, p.d)
    return t

def display(t, order):
    if t:
        if order == 1: print(t.d, end=" ")
        display(t.l, order)
        if order == 2: print(t.d, end=" ")
        display(t.r, order)
        if order == 3: print(t.d, end=" ")

def depth(t):
    return 0 if not t else 1 + max(depth(t.l), depth(t.r))

def mirror(t):
    if t:
        t.l, t.r = mirror(t.r), mirror(t.l)
    return t

def copy(t):
    if not t: return None
    n = Node(t.d)
    n.l, n.r = copy(t.l), copy(t.r)
    return n

def parents(t):
    if t:
        if t.l or t.r:
            print(t.d, ":", t.l.d if t.l else None,
                  t.r.d if t.r else None)
        parents(t.l)
        parents(t.r)

def leaves(t):
    if t:
        if not t.l and not t.r: print(t.d, end=" ")
        leaves(t.l)
        leaves(t.r)

def levels(t):
    q = [t] if t else []
    while q:
        for _ in range(len(q)):
            n = q.pop(0)
            print(n.d, end=" ")
            if n.l: q.append(n.l)
            if n.r: q.append(n.r)
        print()

root = None

while True:
    print("\n1.Insert 2.Delete 3.Search 4.Traversal")
    print("5.Depth 6.Mirror 7.Copy 8.Parents")
    print("9.Leaves 10.Level Wise 11.Exit")
    ch = int(input("Choice: "))

    if ch == 1:
        root = insert(root, int(input("Value: ")))
    elif ch == 2:
        x = int(input("Value: "))
        if search(root, x):
            root = delete(root, x)
            print("Deleted")
        else: print("Not Found")
    elif ch == 3:
        print("Found" if search(root, int(input("Value: "))) else "Not Found")
    elif ch == 4:
        for i, name in enumerate(["Inorder", "Preorder", "Postorder"], 1):
            print(name + ":", end=" ")
            display(root, i)
            print()
    elif ch == 5:
        print("Depth:", depth(root))
    elif ch == 6:
        m = copy(root)
        mirror(m)
        print("Mirror:", end=" ")
        display(m, 2)
        print()
    elif ch == 7:
        c = copy(root)
        print("Copy:", end=" ")
        display(c, 2)
        print()
    elif ch == 8:
        parents(root)
    elif ch == 9:
        leaves(root)
        print()
    elif ch == 10:
        levels(root)
    elif ch == 11:
        break
    else:
        print("Invalid Choice")
