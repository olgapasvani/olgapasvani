/* The database looks like this:

actor (actor_id=int(11)PK, first_name=varchar100, last_name=varchar100, gender=char(1),
film_count = int(11))
◦ actor_id = το id του actor (PK)
◦ first_name = το όνομα του 
◦ last_name = το επώνυμο του 
◦ gender = το φύλο του (M για άντρες, F για γυναίκες)

 director (director_id=int(11)PK, first_name=varchar100, last_name=varchar100)
◦ director_id = το id του director (PK)
◦ first name = το όνομα του 
◦ last_name = το επώνυμο του 

 genre (genre_id=int(11)PK, genre_name=varchar100)
◦ genre_id: το id του είδους για τις ταινίες (PK)
◦ genre_name: η ονομασία του είδους 

 movie (movie_id=int(11)PK, title=varchar(100), year=int(11), rank=double)
◦ movie_id: το id της ταινίας (PK)
◦ title: ο τίτλος της ταινίας 
◦ year: η χρονιά κυκλοφορίας της ταινίας 
◦ rank: rate της ταινίας από 0‐10

 role (movie_id=int(11)PK, actor_id=int(11)PK, role=varchar(100))
◦ movie_id PK, actor_id PK: συσχετίζει έναν ηθοποιό με μια ταινία 
◦ role = ο ρόλος του ηθοποιού στην ταινία 

 movie_has_genre (genre_id PK, movie_id PK)
◦ genre_id PK, movie_id PK:συσχετίζει μια ταινία με ένα είδος

 movie_has_director (movie_id PK, director_id PK)
◦ movie_id PK, director_id PK: συσχετίζει μια ταινία με ένα σκηνοθέτη*/

/*Querys*/

/*1 Find the titles of the movies that feature an actor with the surname “Allen” 
and the genre of the movie is “Comedy”.*/

select m.title
from movie m, 
	role r, 
	actor a, 
	genre g, 
	movie_has_genre mg
where m.movie_id = r.movie_id 
and r.actor_id = a.actor_id 
and a.last_name = 'Allen' 
and m.movie_id = mg.movie_id 
and mg.genre_id = g.genre_id 
and g.genre_name = 'Comedy'


/*2 Find the surnames of the actors who, firstly, 
have acted in at least one movie directed by a director with the same surname, and
secondly, have acted in at least one movie directed by a director with a different surname
but of the same genre as another movie (in which they did not act) directed by the director 
with the same surname.*/

select distinct a.last_name
from actor a, role r, movie m, movie_has_director md, director d1, movie_has_genre mg1, genre g1
where a.actor_id = r.actor_id
and r.movie_id = m.movie_id
and m.movie_id = md.movie_id
and md.director_id = d1.director_id
and d1.last_name = a.last_name
and mg1.movie_id = m.movie_id
and g1.genre_id = mg1.genre_id
and exists (
	select *
    from movie m, director d2, role r, movie_has_director md, movie_has_genre mg2, genre g2
    where a.actor_id = r.actor_id
    and r.movie_id = m.movie_id
    and md.movie_id = m.movie_id
    and md.director_id = d2.director_id
    and d2.last_name != a.last_name
    and m.movie_id = mg2.movie_id
    and mg2.genre_id = g2.genre_id
    and g2.genre_id = mg1.genre_id
)

/*3 Check if there is a movie of the genre “Drama” that was filmed in 1995.
(The query should return a relation with one tuple and one column with the value “yes” or “no”.).*/

(select distinct'yes' as answer 
from movie m,
genre g,
movie_has_genre mhg
where mhg.movie_id=m.movie_id 
and g.genre_id=mhg.genre_id 
and  m.year=1995 
and g.genre_name="Drama")
EXCEPT
(select distinct 'no' as answer 
from movie m,
genre g,
movie_has_genre mhg
where mhg.movie_id!=m.movie_id 
or g.genre_id!=mhg.genre_id 
or m.year!=1995 
or g.genre_name!="Drama")

/*4 For each actor who has acted in exactly 3 movies,find their first name
and last name as well as the number of different directors of their movies.*/

select  a.first_name,a.last_name,count(distinct d.director_id)
from actor a,
role r,
movie m,
director d,
movie_has_director mhd 
where m.movie_id=r.movie_id 
and r.actor_id=a.actor_id  
and d.director_id=mhd.director_id 
and m.movie_id=mhd.movie_id
group by a.first_name, a.last_name, a.actor_id
having count(distinct m.movie_id)=3
order by a.actor_id

/*5 For each movie that has exactly one genre, find the genre
as well as the number of directors who have directed that genre.*/

select g.genre_id, count(distinct d.director_id)
from director d, genre g, movie m, movie_has_genre mg
where m.movie_id = mg.movie_id
	and mg.genre_id = g.genre_id
	and m.movie_id IN (
		select m1.movie_id
        from movie m1, movie_has_genre mg1
        where m1.movie_id = mg1.movie_id
        group by m1.movie_id
        having count(*) = 1
    )
    and d.director_id IN(
		select d1.director_id
        from director d1, movie_has_director md1, movie_has_genre mg1, movie m1
        where md1.director_id = d1.director_id
        and md1.movie_id = m1.movie_id
        and m1.movie_id = mg1.movie_id
        and g.genre_id = mg1.genre_id
    )
    group by g.genre_id

/*6 Find the IDs of the actors who have acted in movies of all genres.*/

select distinct a.actor_id
from actor a
where not exists(
	select g.genre_id
	from genre g
    where not exists(
    select m.movie_id
        from movie m
        where exists (
        select mg.movie_id
        from movie_has_genre mg
        where mg.movie_id = m.movie_id
        and mg.genre_id = g.genre_id
        and exists (
			select r.actor_id
            from role r
            where r.movie_id = m.movie_id
            and r.actor_id = a.actor_id)
		)
	)
)

/*7 For each pair of movie genres (genre_ids), find the number
of directors who have directed movies of both genres.*/

select distinct g1.genre_id, g2.genre_id, count(distinct d.director_id)
from 
	genre g1, 
	genre g2, 
    director d,
    movie_has_genre mg1,
    movie_has_genre mg2,
    movie_has_director md1,
    movie_has_director md2
where g1.genre_id != g2.genre_id
and g1.genre_id < g2.genre_id
and g1.genre_id = mg1.genre_id
and g2.genre_id = mg2.genre_id
and mg1.movie_id = md1.movie_id
and mg2.movie_id = md2.movie_id
and md1.director_id = md2.director_id
and md1.director_id = d.director_id
group by g1.genre_id, g2.genre_id
order by g1.genre_id asc
