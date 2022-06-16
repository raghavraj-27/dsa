# Write your MySQL query statement below
select U.name, if(sum(R.distance) is null, 0, sum(R.distance)) as travelled_distance
from Users U
left join Rides R
on U.id = R.user_id
group by R.user_id
order by travelled_distance desc, U.name asc

