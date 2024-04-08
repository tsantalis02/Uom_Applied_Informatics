# Mean Temperature
print(mean(airquality$Temp))
# Hottest Day
cat("Day: ",airquality$Day[which.max(airquality$Temp)],"Month: ",airquality$Month[which.max(airquality$Temp)],"\n")
# Max wind speed day
cat("Day: ",airquality$Day[which.max(airquality$Wind)],"Month: ",airquality$Month[which.max(airquality$Wind)],"\n")
# Days with temperature greater than 90 Fahrenheit
Greater_Than_90 <- subset(airquality,Temp>90)
print(Greater_Than_90)

# Scatterplot
print(ggplot(airquality, aes(Temp,Wind))+geom_point(shape="x",color="red"))
# Boxplot
print(with(airquality,boxplot(Temp ~ Month, col="bisque")))
# Histogram
print(ggplot(aes(x = Temp, fill = Day), data = airquality) + geom_histogram(binwidth = .1, color="black") + 
        facet_wrap(~Month) + labs(title = "Temperatures By Month", x = "Temperature", y = "Frequency") + 
        scale_x_sqrt())
# Bar chart
print(ggplot(airquality, aes(Temp)) +
        geom_bar(fill="lightblue", position="dodge", width=0.75))