# Write your MySQL query statement below
SELECT SCORE,DENSE_RANK() over (order by score desc) as "rank" from scores ;