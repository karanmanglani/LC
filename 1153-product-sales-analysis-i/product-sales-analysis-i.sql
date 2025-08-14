# Write your MySQL query statement below
-- SubQuery Method
-- SELECT product_name,year,price FROM Sales s,Product p
-- WHERE s.product_id = p.product_id;

-- Join Method
SELECT product_name,year,price FROM Sales s JOIN Product p
ON p.product_id = s.product_id;