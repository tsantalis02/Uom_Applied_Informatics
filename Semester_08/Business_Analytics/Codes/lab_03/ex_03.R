# In this code snippet we try different values for parameters size and shape

library(ggplot2)

print(ggplot(msleep, aes(sleep_total, sleep_rem)) +
  geom_point(colour = "red",size = 3, shape = "x") +
  xlab("Total sleep time (h)"))