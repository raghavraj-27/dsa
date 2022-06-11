# USING SUB QUERY AND NION
# select employee_id from Employees
# where employee_id not in (select employee_id from Salaries)
# union
# select employee_id from Salaries
# where employee_id not in (select employee_id from Employees)
# order by employee_id

# USING FULL JOIN = LEFT JOIN UION RIGHT JOIN
SELECT sub.employee_id
FROM (
    SELECT e.employee_id, name, salary
    FROM Employees AS e
    LEFT JOIN Salaries AS s
    ON e.employee_id = s.employee_id

    UNION

    SELECT s.employee_id, name, salary
    FROM Employees AS e
    RIGHT JOIN Salaries AS s
    ON e.employee_id = s.employee_id) AS sub
WHERE sub.name IS NULL OR sub.salary IS null
ORDER BY sub.employee_id