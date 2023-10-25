# Runtime: 1067ms
# Memory: N/A
SELECT user_id, MAX(time_stamp) as last_stamp
FROM (
  SELECT *
  FROM Logins
  WHERE YEAR(time_stamp) = 2020
) AS L20
GROUP BY L20.user_id
