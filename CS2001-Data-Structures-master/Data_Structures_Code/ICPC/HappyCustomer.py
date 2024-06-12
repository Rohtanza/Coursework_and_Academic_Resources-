# Step 1: Read input values
N, D = map(int, input().split())
package_A, package_B = map(int, input().split())

customers = []

# Step 2: Read customer requirements and indices
for i in range(N):
    size_A, size_B = map(int, input().split())
    total_requirement = size_A * package_A + size_B * package_B
    customers.append((i + 1, total_requirement, size_A, size_B))

# Step 3: Sort customers by total requirements and then by indices
customers.sort(key=lambda x: (x[1], x[0]))

# Step 4: Initialize variables
served_customers = 0
served_indices = []
current_stock_A = D
current_stock_B = D

# Step 5: Serve customers
for customer in customers:
    index, total_requirement, size_A, size_B = customer
    if size_A <= current_stock_A and size_B <= current_stock_B:
        served_customers += 1
        served_indices.append(index)
        current_stock_A -= size_A
        current_stock_B -= size_B

# Step 6: Print the results
print(served_customers)
print(" ".join(map(str, served_indices)))
