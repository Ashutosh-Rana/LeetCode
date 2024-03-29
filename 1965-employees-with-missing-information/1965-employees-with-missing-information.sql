# Write your MySQL query statement below

(select e.employee_id as employee_id
from Employees e
where e.employee_id not in 
(
    select employee_id from Salaries
)
union
select s.employee_id as employee_id
from Salaries s
where s.employee_id not in 
(
    select employee_id from Employees
))
order by employee_id;