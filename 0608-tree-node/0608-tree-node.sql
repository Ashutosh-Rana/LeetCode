# Write your MySQL query statement below
select t.id as id,
case
    when isnull(t.p_id) then "Root"
    when t.id in (select p_id from Tree) then "Inner"
    else "Leaf"
    end as "type"
from Tree t;