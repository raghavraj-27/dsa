# Write your MySQL query statement below
SELECT CUSTOMERS.NAME as "customers" FROM CUSTOMERS LEFT JOIN ORDERS ON CUSTOMERS.ID=ORDERS.CUSTOMERID WHERE ORDERS.ID IS NULL;