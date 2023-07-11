# Write your MySQL query statement below
select  a.sell_date,count(distinct(a.product)) as num_sold,
(
    select group_concat(distinct product order by product)
    from Activities
    where sell_date=a.sell_date
) as products
from Activities a
group by a.sell_date
order by a.sell_date asc;