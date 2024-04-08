# This code snippet computes the mean of height vector and the 
# correlation between height and weight vectors (both with Pearson 
#                 and Spearman correlation).

library(dslabs)


# Compute mean of height vector(from ex_02.R):
print(mean(height))

# Compute the correlation between height and weight(from ex_02.R):
print(cor(height, weight, method="spearman"))
print(cor(height, weight, method="pearson"))