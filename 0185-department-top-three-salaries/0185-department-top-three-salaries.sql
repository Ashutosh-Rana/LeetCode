# Write your MySQL query statement below
select d.name as "Department", e.name as "Employee", e.salary as "Salary"
from Employee e
join Department d
on e.departmentId=d.id
where (
    select count(distinct e2.salary) 
    from Employee e2
    where e.departmentId=e2.departmentId and e.salary<e2.salary
    ) < 3;
