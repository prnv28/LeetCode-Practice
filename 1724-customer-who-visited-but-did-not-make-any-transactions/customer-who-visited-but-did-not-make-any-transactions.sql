SELECT customer_id, COUNT(customer_id) as count_no_trans
FROM Visits 
WHERE visit_id NOT IN (
    SELECT t.visit_id
    FROM Visits as v JOIN Transactions as t
    on v.visit_id=t.visit_id
)
GROUP BY customer_id;

