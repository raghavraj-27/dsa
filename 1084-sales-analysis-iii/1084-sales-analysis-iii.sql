# Write your MySQL query statement below
select P.product_id, P.product_name
from Product as P
left join Sales as S
on P.product_id = S.product_id
group by P.product_id
having min(S.sale_date) >= CAST('2019-01-01' AS DATE) and
max(S.sale_date) <= CAST('2019-03-31' AS DATE)
