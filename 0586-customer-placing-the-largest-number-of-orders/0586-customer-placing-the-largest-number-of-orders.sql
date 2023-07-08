# Write your MySQL query statement below
select T.customer_number
from (
    select o.customer_number,(count(o.order_number)) as "cnt"
    from Orders o
    group by o.customer_number
    order by cnt desc limit 1
    ) T;
