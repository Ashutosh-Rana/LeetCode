# Write your MySQL query statement below
select s.name
from SalesPerson s
where s.sales_id not in
    (
    select s2.sales_id
    from SalesPerson s2,Company c,Orders o
    where s2.sales_id=o.sales_id and c.com_id=o.com_id and c.name="RED"
    )