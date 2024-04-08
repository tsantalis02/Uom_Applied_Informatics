# In this code snippet we plot plot(WHO$GNI,WHO$FertilityRate) with ggplot
library(ggplot2)

print(ggplot(WHO, aes(GNI, FertilityRate)) + geom_point())