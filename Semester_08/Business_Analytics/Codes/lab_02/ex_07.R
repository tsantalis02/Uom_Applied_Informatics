#This code snippet creates a scatterplot with total sleeping time 
# along the x-axis and time awake along the y-axis (using the msleep 
#                    data from ggplot2 library). 

library(ggplot2)

print(ggplot(msleep,aes(x=sleep_total,y=awake)) + geom_point())