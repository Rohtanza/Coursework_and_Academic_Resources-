import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad


# plotting function to save our plots in the dir
def plot_function(f, x_range, title, xlabel, ylabel, filename=None):
    x = np.linspace(x_range[0], x_range[1], 1000)
    y = f(x)
    plt.plot(x, y)
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)

    if filename:
        plt.savefig(filename)  # Save plot
    else:
        plt.show()


# Monte Carlo function to estimate area
def monte_carlo_area(f, x_range, num_darts):
    x_min, x_max = x_range
    y_min, y_max = min(f(np.linspace(x_min, x_max, 1000))), max(f(np.linspace(x_min, x_max, 1000)))

    inside = 0
    for _ in range(num_darts):
        x = np.random.uniform(x_min, x_max)
        y = np.random.uniform(y_min, y_max)

        if y <= f(x):
            inside += 1

    rectangle_area = (x_max - x_min) * (y_max - y_min)
    return (inside / num_darts) * rectangle_area


# Mean and standard deviation function 
def monte_carlo_stats(f, x_range, num_darts, num_trials):
    results = []
    for _ in range(num_trials):
        estimate = monte_carlo_area(f, x_range, num_darts)
        results.append(estimate)

    mean = np.mean(results)
    std_dev = np.std(results)
    return mean, std_dev


# function to calculate area using integration
def calculate_integral(f, x_range):
    result, _ = quad(f, x_range[0], x_range[1])
    return result


# function to calculate percentage error
def percentage_error(analytical_solution, monte_carlo_mean):
    return abs((analytical_solution - monte_carlo_mean) / analytical_solution) * 100


# now one by one we will apply the functions to the each question of the assignment

# Question 1: f(x) = sqrt(sin^2(x) + 1), x = 0 to 2
f1 = lambda x: np.sqrt(np.sin(x ** 2) + 1)

# Part a: Plotting the function and saving it
plot_function(f1, (0, 2), "f(x) = sqrt(sin^2(x) + 1)", "x", "y", "plot1.png")

# Part b: Monte Carlo estimate
monte_carlo_estimate_1 = monte_carlo_stats(f1, (0, 2), 1000, 1000)

# Part c: Mean and standard deviation
mean_1, std_dev_1 = monte_carlo_estimate_1

# Part d: Integration
integrated_result_1 = calculate_integral(f1, (0, 2))

# Part e: Percentage error
percentage_err_1 = percentage_error(integrated_result_1, mean_1)

print("Question 1 Values:")
print("Monte Carlo Mean:", mean_1)
print("Standard Deviation:", std_dev_1)
print("Integrated Result:", integrated_result_1)
print("Percentage Error:", percentage_err_1)

# Question 2: f(x) = x^3, x = 2 to 3
f2 = lambda x: x ** 3

# Part a: Plotting the function and saving it
plot_function(f2, (2, 3), "f(x) = x^3", "x", "y", "plot2.png")

# Part b: Monte Carlo estimate
monte_carlo_estimate_2 = monte_carlo_stats(f2, (2, 3), 1000, 1000)

# Part c: Mean and standard deviation
mean_2, std_dev_2 = monte_carlo_estimate_2

# Part d: Integration
integrated_result_2 = calculate_integral(f2, (2, 3))

# Part e: Percentage error
percentage_err_2 = percentage_error(integrated_result_2, mean_2)

print("Question 2 Values:")
print("Monte Carlo Mean:", mean_2)
print("Standard Deviation:", std_dev_2)
print("Integrated Result:", integrated_result_2)
print("Percentage Error:", percentage_err_2)

# Question 3: f(x) = cos(x^2), x = 2 to 3
f3 = lambda x: np.cos(x ** 2)

# Part a: Plotting the function and saving it
plot_function(f3, (2, 3), "f(x) = cos(x^2)", "x", "y", "plot3.png")

# Part b: Monte Carlo estimate
monte_carlo_estimate_3 = monte_carlo_stats(f3, (2, 3), 1000, 1000)

# Part c: Mean and standard deviation
mean_3, std_dev_3 = monte_carlo_estimate_3

# Part d: Integration
integrated_result_3 = calculate_integral(f3, (2, 3))

# Part e: Percentage error
percentage_err_3 = percentage_error(integrated_result_3, mean_3)

print("Question 3 Values:")
print("Monte Carlo Mean:", mean_3)
print("Standard Deviation:", std_dev_3)
print("Integrated Result:", integrated_result_3)
print("Percentage Error:", percentage_err_3)