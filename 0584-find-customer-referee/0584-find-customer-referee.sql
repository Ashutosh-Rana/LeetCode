# Write your MySQL query statement below
select c.name
from Customer c
where c.referee_id<>2 OR ISNULL(c.referee_id);