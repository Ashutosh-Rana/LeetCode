# Write your MySQL query statement below
# delete p1
# from Person p1
# where p1.id not in (
#     select t.id 
#     from (select min(p2.id) as id
#         from Person p2
#         group by p2.email) t 
#     );

# delete from Person where id not in( 
#     select t.id from (
#         select min(id) as id from Person group by email
#     ) t
# )

# select * from Person
# where p1.email=p2.email and p1.id>min(p2.id);
# (select min(p2.id)
#         from Person p2
#         group by p2.email);

# delete p1
# from Person p1,Person p2
# where p1.email=p2.email and p1.id<(p2.id);

select min(p1.id) as "id",p1.email
from Person p1
group by p1.email;