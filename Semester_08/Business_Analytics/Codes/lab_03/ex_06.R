# Histogram of diamond prices
print(ggplot(diamonds, aes(price)) +
  geom_histogram())
# Histograms of diamond prices for different cuts, using facetting
print(ggplot(aes(x = price, fill = cut), data = diamonds) + geom_histogram(binwidth = .1) + 
       facet_wrap(~color) + labs(title = "Diamond Prices by Color", x = "Price", y = "Frequency") + 
      scale_x_log10())
# Histograms of diamond prices for different cuts, using facetting with black outlines around the bars
print(ggplot(aes(x = price, fill = cut), data = diamonds) + geom_histogram(binwidth = .1, color="black") + 
        facet_wrap(~color) + labs(title = "Diamond Prices by Color", x = "Price", y = "Frequency") + 
        scale_x_log10())