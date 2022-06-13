# Write your MySQL query statement below
select name from SalesPerson
where sales_id not in (
    # select sales_id from Orders as o
    # left join company as c
    # on o.com_id = c.com_id
    # where o.name = "RED"
    
    select O.sales_id from Orders as O
    left join Company as C
    ON O.com_id = C.com_id
    where C.name = "RED"
    
#     union
    
#     select sales_id from SalesPerson
#     where sales_id not in (select sales_id from orders )
)

# union
    
#     select name from SalesPerson
#     where sales_id not in (select sales_id from orders )