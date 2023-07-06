# Write your MySQL query statement below
select d.name as "Department",e.name as "Employee", e.salary as "Salary"
# select e.id,d.name,e.salary
from Employee e, Department d,
    (select e2.departmentId,max(e2.salary) as maxm
    from Employee e2
    group by e2.departmentId) T
where e.departmentId=T.departmentId and e.salary=T.maxm and e.departmentId=d.id;
