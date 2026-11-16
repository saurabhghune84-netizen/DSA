
def knapsack(w, p, capacity):
    items = sorted(zip(w, p), key=lambda x: x[1]/x[0], reverse=True)
    profit = 0

    for weight, value in items:
        if capacity == 0:
            break

        if weight <= capacity:
            profit += value
            capacity -= weight
        else:
            profit += value * capacity / weight
            capacity = 0

    return profit


n = int(input("Enter number of parcels: "))
w = list(map(int, input("Enter weights: ").split()))
p = list(map(int, input("Enter profits: ").split()))
capacity = int(input("Enter truck capacity: "))

print("Maximum Profit:", knapsack(w, p, capacity))
