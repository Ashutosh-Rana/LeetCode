# Write your MySQL query statement below
select sell.stock_name,sell.sell_price-buy.buy_price as capital_gain_loss
from 
(
    select s.stock_name, sum(s.price) as sell_price
    from Stocks s
    where s.operation="Sell"
    group by s.stock_name
) sell,
(
    select s.stock_name, sum(s.price) as buy_price
    from Stocks s
    where s.operation="Buy"
    group by s.stock_name
) buy
where sell.stock_name=buy.stock_name;