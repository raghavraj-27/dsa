# select Employees.employee_id as employee_id
# from Employees
# outer join Salaries
# on Employees.employee_id = Salaries.employee_id
# where Employees.name is null or Salaries.salary is null

select employee_id from Employees
where employee_id not in (select employee_id from Salaries)
union
select employee_id from Salaries
where employee_id not in (select employee_id from Employees)
order by employee_id

# select Employees.employee_id from Employees
# where Employees.employee_id not in (select Salaries.employee_id from Salaries)
# union
# select Salaries.employee_id from Salaries
# where Salaries.employee_id not in (select Employees.employee_id from Employees)
# order by Salaries.employee_id 



# select Employees.employee_id from Employees 
# left join Salaries 
# on Employees.employee_id <> Salaries.employee_id
# where Employees.name is null
# union
# select Salaries.employee_id from Salaries 
# right join Employees 
# on Employees.employee_id <> Salaries.employee_id
# where Salaries.salary is null