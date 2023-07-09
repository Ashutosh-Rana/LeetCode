# Write your MySQL query statement below
# select s.id,s.name,
# case
#     when s.sex="m" then "f"
#     when s.sex="f" then "m"
# end as "sex", s.salary
# from Salary s;

update Salary s
set s.sex=
case 
    when s.sex="m" then "f"
    when s.sex="f" then "m"
end;