# Base R:
# print(boxplot(price ~ cut, data = diamonds))
# ggplot2 (1,2)  : 
print(ggplot(diamonds, aes(cut,price))+geom_boxplot(aes(group = cut_width(cut,0.25)),fill = "white", colour = "#3366FF", outlier.shape = 1))
# 3.
print(ggplot(diamonds, aes(cut,price))+geom_boxplot(aes(reorder(cut,price,median)),fill = "white", colour = "#3366FF", outlier.shape = 1))
# 4.
print(ggplot(diamonds, aes(cut,price))+geom_boxplot(aes(reorder(cut,price,median)),fill = "white", colour = "#3366FF", outlier.shape = 1)+geom_jitter(size = 0.1, alpha = 0.2))