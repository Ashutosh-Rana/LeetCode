# Write your MySQL query statement bel
SELECT d.date_id,d.make_name,COUNT(DISTINCT d.lead_id) as unique_leads,COUNT(DISTINCT d.partner_id) as unique_partners
FROM DailySales d
GROUP BY d.date_id,d.make_name;