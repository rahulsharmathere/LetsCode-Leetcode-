# Write your MySQL query statement below
(select name as results
from MovieRating join Users 
ON MovieRating.user_id = Users.user_id
group by name
order by COUNT(*) DESC, name
LIMIT 1)

UNION ALL

(select title AS results
from MovieRating join Movies 
ON MovieRating.movie_id = Movies.movie_id
where created_at between '2020-02-01' AND '2020-02-29'
group by title
order by AVG(rating) DESC, title
LIMIT 1)