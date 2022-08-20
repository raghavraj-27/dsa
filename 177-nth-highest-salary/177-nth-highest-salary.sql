CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
set N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT distinct(SALARY) FROM EMPLOYEE ORDER  BY SALARY DESC LIMIT 1 offset N
  );
END