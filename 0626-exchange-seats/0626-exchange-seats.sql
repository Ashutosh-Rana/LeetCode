# Write your MySQL query statement below
select distinct s.id,
case 
    when s.id%2=1 and s2.id is not null then s2.student
    when s.id%2=0 then (select student from Seat where id=s.id-1)
    when s.id%2=1 and s2.id is null then s.student
    end as "student"
from Seat s
left join Seat s2 on s.id+1=s2.id;