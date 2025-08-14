# Write your MySQL query statement below
SELECT 
    (SELECT eu.unique_id FROM EmployeeUNI eu WHERE eu.id = ep.id) AS unique_id,
    ep.name
FROM Employees ep;
