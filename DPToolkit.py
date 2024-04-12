def fibonacci(n):
    fib = [0, 1]
    for i in range(2, n + 1):
        fib.append(fib[i - 1] + fib[i - 2])
    return fib[n]

def knapsack(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, capacity + 1):
            if weights[i - 1] > j:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]])
    return dp[n][capacity]

def tsp(graph):
    n = len(graph)
    dp = [[float('inf')] * (1 << n) for _ in range(n)]
    dp[0][1] = 0
    for mask in range(1, (1 << n)):
        for u in range(n):
            if mask & (1 << u):
                for v in range(n):
                    if v != u and mask & (1 << v):
                        dp[v][mask] = min(dp[v][mask], dp[u][mask ^ (1 << v)] + graph[u][v])

    return min(dp[i][(1 << n) - 1] + graph[i][0] for i in range(1, n))

def longest_common_subsequence(X, Y):
    m = len(X)
    n = len(Y)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    lcs_length = dp[m][n]
    lcs = [''] * (lcs_length + 1)
    i = m
    j = n
    while i > 0 and j > 0:
        if X[i - 1] == Y[j - 1]:
            lcs[lcs_length - 1] = X[i - 1]
            i -= 1
            j -= 1
            lcs_length -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    return ''.join(lcs)

def edit_distance(X, Y):
    m = len(X)
    n = len(Y)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif X[i - 1] == Y[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
    return dp[m][n]

def longest_increasing_subsequence(nums):
    n = len(nums)
    dp = [1] * n
    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)

def matrix_chain_multiplication(p):
    n = len(p)
    dp = [[0] * n for _ in range(n)]
    for length in range(2, n):
        for i in range(1, n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]
                if cost < dp[i][j]:
                    dp[i][j] = cost
    return dp[1][n - 1]

def coin_change(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[amount]

def main():
    while True:
        print("\nChoose an application of dynamic programming:")
        print("1. Fibonacci Sequence")
        print("2. 0/1 Knapsack Problem")
        print("3. Traveling Salesman Problem (TSP)")
        print("4. Longest Common Subsequence")
        print("5. Edit Distance")
        print("6. Longest Increasing Subsequence")
        print("7. Matrix Chain Multiplication")
        print("8. Coin Change")
        print("9. Exit")
        choice = input("Enter your choice: ")
        if choice == "1":
            print("The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones, usually starting with 0 and 1.\n\nThe Fibonacci sequence can be computed using dynamic programming. We store previously computed Fibonacci numbers in an array and use them to compute subsequent Fibonacci numbers iteratively.")
            n = int(input("Enter the value of n for Fibonacci sequence: "))
            print("Fibonacci({}) = {}".format(n, fibonacci(n)))
        elif choice == "2":
            print("The 0/1 knapsack problem involves choosing a subset of items with maximum value while ensuring that the total weight of the selected items does not exceed a given capacity.\n\nWe solve the 0/1 knapsack problem using dynamic programming. We create a table to store the maximum value that can be achieved for different capacities and numbers of items. We fill the table iteratively, considering whether to include each item in the knapsack or not.")
            n = int(input("Enter the number of items: "))
            weights = list(map(int, input("Enter the weights of the items: ").split()))
            values = list(map(int, input("Enter the values of the items: ").split()))
            capacity = int(input("Enter the knapsack capacity: "))
            print("Maximum value in knapsack:", knapsack(weights, values, capacity))
        elif choice == "3":
            print("The traveling salesman problem involves finding the shortest possible route that visits each city exactly once and returns to the original city.\n\nWe solve the traveling salesman problem using dynamic programming. We create a table to store the minimum cost of reaching each city while visiting a subset of cities. We fill the table iteratively, considering all possible subsets of cities and choosing the minimum cost route.")
            n = int(input("Enter the number of cities: "))
            graph = []
            print("Enter the cost matrix (enter 'inf' for unreachable cities):")
            for _ in range(n):
                row = input().split()
                graph.append([float('inf') if x == 'inf' else int(x) for x in row])
            print("Minimum cost for TSP:", tsp(graph))
        elif choice == "4":
            print("The longest common subsequence problem involves finding the longest subsequence that is present in both of the given sequences (strings).\n\nWe solve the longest common subsequence problem using dynamic programming. We create a table to store the length of the longest common subsequence for different prefixes of the input sequences. We fill the table iteratively, considering whether characters match or not.")
            X = input("Enter the first sequence: ")
            Y = input("Enter the second sequence: ")
            print("Longest Common Subsequence:", longest_common_subsequence(X, Y))
        elif choice == "5":
            print("Edit distance, also known as Levenshtein distance, is a measure of similarity between two strings represented as the minimum number of operations required to convert one string into the other.\n\nWe solve the edit distance problem using dynamic programming. We create a table to store the minimum number of operations required to convert substrings of the input strings into each other. We fill the table iteratively, considering insertion, deletion, or substitution operations.")
            X = input("Enter the first string: ")
            Y = input("Enter the second string: ")
            print("Edit Distance:", edit_distance(X, Y))
        elif choice == "6":
            print("The longest increasing subsequence problem involves finding the length of the longest subsequence in an array such that all elements of the subsequence are sorted in increasing order.\n\nWe solve the longest increasing subsequence problem using dynamic programming. We create an array to store the length of the longest increasing subsequence ending at each index. We fill the array iteratively, considering all previous elements and choosing the maximum length.")
            nums = list(map(int, input("Enter the array: ").split()))
            print("Length of Longest Increasing Subsequence:", longest_increasing_subsequence(nums))
        elif choice == "7":
            print("Given a sequence of matrices, the matrix chain multiplication problem involves finding the most efficient way to multiply these matrices together, minimizing the total number of scalar multiplications.\n\nWe solve the matrix chain multiplication problem using dynamic programming. We create a table to store the minimum number of scalar multiplications needed to multiply each subchain of matrices. We fill the table iteratively, considering all possible ways to split the chain and choosing the split with the minimum cost.")
            dimensions = list(map(int, input("Enter the dimensions of matrices: ").split()))
            print("Minimum number of multiplications:", matrix_chain_multiplication(dimensions))
        elif choice == "8":
            print("The coin change problem involves finding the minimum number of coins needed to make up a given target amount using a set of coin denominations.\n\nWe solve the coin change problem using dynamic programming. We create an array to store the minimum number of coins required to make up each target amount. We fill the array iteratively, considering all possible coin denominations and choosing the minimum number of coins needed for each amount.")
            coins = list(map(int, input("Enter the coin denominations: ").split()))
            amount = int(input("Enter the target amount: "))
            print("Minimum number of coins required:", coin_change(coins, amount))
        elif choice == "9":
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a valid option.")
if __name__ == "__main__":
    main()
