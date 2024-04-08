# Bar chart of diamond cuts
print(ggplot(diamonds, aes(cut)) +
   geom_bar())
# Bar chart of diamond cuts with colors
print(ggplot(diamonds, aes(cut)) +
   geom_bar(fill="lightblue"))
# Bar chart of diamond cuts with colors and decreased width
print(ggplot(diamonds, aes(cut)) +
   geom_bar(fill="lightblue",width=0.75))
# Bar chart of diamond cuts with fill=clarity
print(ggplot(diamonds, aes(cut,fill=clarity)) +
   geom_bar())
# Bar chart of diamond cuts with fill=clarity and position="dodge"
print(ggplot(diamonds, aes(cut,fill=clarity)) +
        geom_bar(position="dodge"))
# Bar chart of diamond cuts and coord_flip()
print(ggplot(diamonds, aes(cut)) +
   geom_bar()+coord_flip())