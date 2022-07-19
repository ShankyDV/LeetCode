# Write your MySQL query statement below
SELECT
id,
CASE WHEN p_id is null THEN 'Root'
WHEN id IN (SELECT DISTINCT p_id FROM tree) AND p_id is NOT null THEN 'Inner'
ELSE 'Leaf' END AS Type
FROM tree