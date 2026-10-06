# Smart-Delivery-Planning-
A delivery company has a vehicle with a fixed carrying capacity and a set of packages. Each package has a weight and an associated value or profit. The vehicle can carry packages up to its maximum capacity. A complete package or a fraction of a package can be selected. The objective is to maximize the total value carried by the vehicle. This program implements the Fractional Knapsack Greedy Algorithm to determine the maximum possible value that can be carried within the given vehicle capacity.

Objectives
Understand and implement the Greedy Method.
Calculate the Value/Weight ratio for every package.
Arrange packages in decreasing order of Value/Weight ratio.
Select complete packages whenever possible.
Select a fraction of a package when the complete package cannot fit.
Calculate and display the maximum achievable value.
Display the total weight used and quantity or fraction selected for each package.
Analyze the time complexity of the solution.

Input
Number of packages.
Value or profit of each package.
Weight of each package.
Maximum carrying capacity of the vehicle.

Menu
Enter Package Details
Display Package Details
Calculate Value/Weight Ratio
Sort Packages by Ratio
Find Maximum Value
Display Selected Packages
Exit

Algorithm
Read the number of packages and vehicle capacity.
Read the value and weight of each package.
Calculate the Value/Weight ratio for every package.
Sort the packages in decreasing order of their Value/Weight ratio using Merge Sort.
Start with the full vehicle capacity.
Select packages in decreasing order of their ratio.
If the complete package fits, select the entire package.
If the complete package does not fit, select the fraction that can fit in the remaining capacity.
Calculate the value obtained from each selected package.
Continue until the vehicle capacity is full or all packages have been considered.
Display the selected quantity or fraction, total weight used, and maximum value obtained.

Greedy Strategy
The greedy choice is based on the Value/Weight ratio.
Value/Weight Ratio = Value / Weight
Packages are sorted in decreasing order of this ratio before the selection process begins.

Implementation Details
Programming Language: C
Data Structure: Arrays
Sorting Algorithm: Merge Sort
Optimization Technique: Greedy Method
Fractional selection is allowed.
Packages are represented using separate arrays rather than structures.
Functions are used to divide the program into manageable operations.

Functions
The program contains functions for:
Entering package details.
Displaying package details.
Calculating Value/Weight ratios.
Sorting packages using Merge Sort.
Finding the maximum achievable value.
Displaying the selected packages.

Expected Output
The program displays:
Package details.
Value/Weight ratio of each package.
Packages arranged in decreasing order of ratio.
Quantity or fraction selected for each package.
Total weight used.
Maximum value obtained.

Time Complexity
Calculating Value/Weight ratios: O(n)
Merge Sort: O(n log n)
Greedy selection: O(n)
Therefore, the overall time complexity is O(n log n), because Merge Sort is the dominant operation.

Space Complexity
Merge Sort uses temporary arrays during the merging process.
Therefore, the space complexity is O(n).

AOA Concepts Covered
Greedy Method
Fractional Knapsack
Value/Weight ratio
Ratio-based selection
Sorting
Merge Sort
Time complexity analysis
Space complexity analysis
