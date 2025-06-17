SELECT customer_id, COUNT(customer_id) as count_no_trans
FROM Visits as v LEFT OUTER JOIN Transactions as t
on v.visit_id=t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id
ORDER BY count_no_trans ASC;
