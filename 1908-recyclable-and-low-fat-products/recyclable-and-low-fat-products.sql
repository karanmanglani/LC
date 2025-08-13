# Write your MySQL query statement below
SELECT prod.product_id FROM Products as prod
WHERE prod.low_fats = 'Y' && prod.recyclable = 'Y';