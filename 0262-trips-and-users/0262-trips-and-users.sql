# Write your MySQL query statement below
select t1.request_at as "Day",
    ROUND(sum(case when t1.status="cancelled_by_driver" or t1.status="cancelled_by_client" then 1 else 0 end)/count(t1.status),2) as "Cancellation Rate"
from Trips t1
where 
    t1.client_id in (select users_id from Users where role="client" and banned="No") and
    t1.driver_id in (select users_id from Users where role="driver" and banned="No")
and t1.request_at>="2013-10-01" and t1.request_at<="2013-10-03"
group by t1.request_at;