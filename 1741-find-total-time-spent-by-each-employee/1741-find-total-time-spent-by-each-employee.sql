# Write your MySQL query statement below
select e.event_day as day,e.emp_id,sum(e.out_time)-sum(e.in_time) as total_time
from Employees e
group by e.emp_id,e.event_day
