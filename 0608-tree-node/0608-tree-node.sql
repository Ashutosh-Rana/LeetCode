# Write your MySQL query statement below
# select t.id as id,
# case
#     when isnull(t.p_id) then "Root"
#     when t.id in (select p_id from Tree) then "Inner"
#     else "Leaf"
#     end as "type"
# from Tree t;


select distinct t.id as id,
case
    when isnull(t.p_id) then "Root"
    when t.p_id is not null and t2.id is null then "Leaf"
    when t.p_id is not null and t2.id is not null then "Inner"
    end as "type"
from Tree t
left join Tree t2 on t.id=t2.p_id;

# select t.id
# from Tree t
# where t.id in (select p_id from Tree)
