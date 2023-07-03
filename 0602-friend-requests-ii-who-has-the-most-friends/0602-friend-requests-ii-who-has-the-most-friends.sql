# Write your MySQL query statement below
select tb.id,count(*) as  num
from
( 
    (select accepter_id as id from  RequestAccepted) 
    union all
    (select requester_id as id from RequestAccepted)
) tb
group by tb.id
order by num desc limit 1;

 
