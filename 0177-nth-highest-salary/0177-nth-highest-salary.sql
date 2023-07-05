CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare offset_val int;
set offset_val=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select ifnull((select distinct e.salary
                    from Employee e
                    order by e.salary desc limit offset_val,1),null)
  );
END