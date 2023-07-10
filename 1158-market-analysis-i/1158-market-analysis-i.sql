# Write your MySQL query statement below
# select u.user_id as buyer_id, u.join_date,
# (
#     select count(order_id)
#     from Orders
#     where buyer_id=u.user_id and 
#     order_date>="2019-01-01" and order_date<="2019-12-31"
# ) as orders_in_2019
# from Orders o,Users u 
# where u.user_id=o.buyer_id
# group by u.user_id;

select u.user_id as buyer_id, u.join_date, 
(select count(o.order_id)) as orders_in_2019
from Users u
left join Orders o on u.user_id=o.buyer_id and year(o.order_date)="2019"
group by u.user_id;
