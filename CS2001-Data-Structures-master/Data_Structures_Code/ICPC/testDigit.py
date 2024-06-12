N, D = map(int, input().split())
A, B = map(int, input().split())
customers = [(i+1, *map(int, input().split())) for i in range(N)]

customers.sort(key=lambda x: A * x[1] + B * x[2])

served_customers = []
packages_A = D
packages_B = D

for customer in customers:
    index, packages_of_A, packages_of_B = customer
    if packages_A >= packages_of_A and packages_B >= packages_of_B:
        packages_A -= packages_of_A
        packages_B -= packages_of_B
        served_customers.append(index)

print(len(served_customers))
print(" ".join(map(str, served_customers)))