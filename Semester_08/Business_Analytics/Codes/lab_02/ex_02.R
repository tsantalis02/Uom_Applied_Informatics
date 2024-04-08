# This code snippet creates two vectors and then combines them 
#                    in one data frame. 

library(dslabs)

#Create height and weight vectors for 5 people:
height <- c(165,179,175,168,190) # height in cm
weight <- c(70,85,90,55,105) #weight in kg

# Combine height and weight:
people <- data.frame(height,weight)
print(people)
