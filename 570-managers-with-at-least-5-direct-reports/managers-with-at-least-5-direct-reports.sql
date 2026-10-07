# Write your MySQL query statement below
SELECT b.name 
FROM Employee a JOIN Employee b
ON a.managerId=b.id
GROUP BY b.id
HAVING COUNT(a.id)>=5;
