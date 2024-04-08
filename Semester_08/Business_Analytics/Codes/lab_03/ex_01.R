# In this code snippet we add a new variable rev_per_minute 
# which is the ratio between purchase and the visit length and
# we replace the purchase amount for the 80-year old customer with 16.

age <- c(28, 48, 47, 71, 22, 80, 48, 30, 31)
purchase <- c(20, 59, 2, 12, 22, 160, 34, 34, 29)
bookstore <- data.frame(age, purchase)
bookstore$visit_length <- c(5, 2, 20, 22, 12, 31, 9, 10, 11)
bookstore$rev_per_minute <- bookstore$purchase / bookstore$visit_length
bookstore[6,2] <- 16
print(bookstore)