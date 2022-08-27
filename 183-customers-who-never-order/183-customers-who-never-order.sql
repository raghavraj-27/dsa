# Write your MySQL query statement below
# select name as Customers from Customers
# where id not in (
# select customerId from Orders)

select name as Customers from Customers C
left join Orders O
on C.id = O.customerId
where O.id is null;