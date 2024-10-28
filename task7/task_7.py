def hit_target(n):
    # Initialize the dp table
    dp = [0 for _ in range(n+1)]
    
    # Base case: if n is 2, then two shots at the same spot solve the problem
    dp[2] = 2

    # Fill the dp table
    for i in range(3, n+1):
        dp[i] = 2 * (i - 1) + 2  # Add 2 for the extra shots at the second to last spot

    # Initialize the shot counter
    shot_counter = 0

    # Sequence of shots for n > 2
    shots = list(range(2, n)) + [n-1, n-1] + list(range(n-1, 1, -1)) + [2, 2]
    for shot in shots:
        print(f"Shooting at spot {shot}.")
        shot_counter += 1
        result = input("Did the shot hit the target? (yes/no): ")
        if result.lower() == 'yes':
            return f"Target hit at spot {shot} after {shot_counter} shots!"
        else:
            print("Target missed. Moving to the next spot.")

    return f"Minimum shots needed to guarantee a hit: {dp[n]}"

# Example usage:
print(hit_target(10))
