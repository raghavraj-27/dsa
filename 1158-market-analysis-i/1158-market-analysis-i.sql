# Write your MySQL query statement below
select U.user_id as buyer_id, U.join_date, if(count(O.order_date) is null, 0, count(O.order_date)) as orders_in_2019
from Users as U
left join Orders as O
on O.buyer_id = U.user_id
and YEAR(O.order_date) = '2019' 
group by user_id