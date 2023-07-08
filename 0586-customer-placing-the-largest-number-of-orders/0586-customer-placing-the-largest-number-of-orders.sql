# Write your MySQL query statement below
select T.customer_number
from (
    select o.customer_number,(count(o.order_number)) as "cnt"
    from Orders o
    group by o.customer_number
    having cnt=(
        select max(c)
        from (select count(*) as "c" from Orders group by customer_number) t
        )
    # order by cnt desc limit 1
    ) T;
