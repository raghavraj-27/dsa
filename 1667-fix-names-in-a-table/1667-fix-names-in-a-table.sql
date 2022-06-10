# Write your MySQL query statement below
# update Users
# set name = UPPER(LEFT(name, 1)) + LOWER(SUBSTRING(name, 1, len(name)))

select user_id, CONCAT(UPPER(SUBSTR(name, 1, 1)), LOWER(SUBSTR(name, 2))) as name
from Users
order by user_id