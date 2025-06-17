SELECT B.id 
FROM Weather as A JOIN Weather as B
WHERE DATEDIFF(B.recordDate,A.recordDate)=1 AND a.temperature<B.temperature;
