# Write your MySQL query statement below
select IFNULL((select distinct e.salary
from Employee e
order by e.salary desc limit 1,1),null) as "SecondHighestSalary";

# select IFNULL((SELECT DISTINCT Salary FROM Employee order by Salary desc limit 1,1),null)