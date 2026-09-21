# Write your MySQL query statement below
SELECT contest_id,ROUND(COUNT(distinct user_id)*100.0/(select count(user_id) from Users),2) AS percentage
FROM Register 
GROUP BY contest_id
ORDER BY percentage DESC , contest_id ASC;