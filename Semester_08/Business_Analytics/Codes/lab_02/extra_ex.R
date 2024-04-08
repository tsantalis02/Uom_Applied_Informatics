# This code snippet creates a scatterplot with GNI the x-axis and 
# FertilityRate the y-axis (from WHO dataset) using ggplot2 library.

library(ggplot2)

print(ggplot(WHO, aes(x=GNI,y=FertilityRate)) + geom_point())