# Mastering_DP_ass1


## Question 1
In the first question I created 3 of my own data_types for the question which are pretty straight forward.<br>
struct product{} is for the details of a product.<br>
struct log{} is for storing transactions.<br>
account{} is just to keep track of the stores balance of money and its loan.<br>
I also used unordered_map to connect the product IDs to their stock and details about sale price and cost price.<br>
I solved the question by first taking the enquiries of each customer seperately and then for the optimal payoff for the customer in the given budget i applied the generic knapsack problem approach and to get the bill i went back through my purchases and made a bill out of them.<br>
Then I made an update function to update the stock and take the loan, update the money accordingly, also I stored all the transactions.<br>
Then I printed out all the transactions made today + the repayment of the loan and in the end the net profit made today.<br>
