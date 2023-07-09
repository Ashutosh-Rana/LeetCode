# Write your MySQL query statement below
select p.product_id,p.product_name
from Product p,
    (
     select s.product_id, count(*)  as "cnt"
     from Sales s
     where s.sale_date>="2019-01-01" and s.sale_date<="2019-03-31"
     group by s.product_id
    ) T1,
    (
     select s.product_id, count(*)  as "cnt"
     from Sales s
     group by s.product_id
    ) T2
where p.product_id=T1.product_id and T1.product_id=T2.product_id and T1.cnt=T2.cnt;
