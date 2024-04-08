
# Coldest Day
cat("Day: ",airquality$Day[which.min(airquality$Temp)],"Month: ",airquality$Month[which.min(airquality$Temp)],"\n")

# Days with wind speed greater than 17 mph
print(sum(airquality$Wind > 17))

# Missing values in the ozone vector
print(sum(is.na(airquality$Ozone)))

# Days with temperature below 70 and wind speed above 10
print(sum(airquality$Temp < 70 & airquality$Wind > 10))