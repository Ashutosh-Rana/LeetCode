# Write your MySQL query statement below
select t.class 
from (
    select c.class,count(*) as cnt
    from Courses c
    group by c.class
    having cnt>=5
    ) t;

