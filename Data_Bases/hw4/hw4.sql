-- Q1 Τα album που περιέχουν στον τίτλο τους τη λέξη Best.
select *
from album
where album.Title like '%Best%';

-- Q2  Ποια album των Led Zeppelin καταχωρεί η βάση;
select album.AlbumId,album.Title
from album,artist
where album.ArtistId=artist.ArtistId and artist.Name="Led Zeppelin";

-- Q3  Το πλήθος των κομματιών (track) για κάθε είδος (genre) σε φθίνουσα κατάταξη
--     ως προς το πλήθος.
select genre.Name,count(TrackId)
from genre join track using(GenreId)
group by GenreId
order by count(TrackId) desc;

-- Q4 Για κάθε υπάλληλο, το πλήθος των πελατών που εξυπηρετεί.
--     Να εμφανίζονται και οι υπάλληλοι που δεν εξυπηρετούν κανέναν πελάτη. 
select employee.FirstName,employee.LastName,count(*)
from employee  join customer on EmployeeId=SupportRepId
group by EmployeeId;
union
select employee.FirstName,employee.LastName,0
from customer
where EmployeeId not in(select SupportRepId from customer);

-- Q5 Συνδυασμοί φορμά ( media_type) και είδους μουσικής που έχουν πάνω από 50 κομμάτια
--     σε φθίνουσα κατάταξη ως προς το πλήθος. 
select track
from (track join mediatype using(MediaTypeId))join genre using(GenreId)
where(select count(*) from (track join mediatype using(MediaTypeId))join genre using(GenreId) > 50);