--runtime: 1121ms
SELECT user_id, MAX(time_stamp) AS last_stamp
FROM Logins
WHERE Year(time_stamp) = 2020
GROUP BY user_id;