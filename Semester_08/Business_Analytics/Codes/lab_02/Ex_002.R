
library(ggplot2)


# Compute pearson correlation and plot histograms for variables x and z

 print(cor(diamonds$x,diamonds$z,method="pearson"))
 print(ggplot(diamonds,aes(x=x,y=z)) + geom_point())


# Compute pearson correlation and plot histograms for variables depth and table 

 print(cor(diamonds$depth,diamonds$table,method="pearson"))
 print(ggplot(diamonds,aes(x=depth,y=table)) + geom_point())

