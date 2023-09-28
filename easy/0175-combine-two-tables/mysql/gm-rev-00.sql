# Runtime 931ms
# Memory 0.00MB
SELECT Person.firstName, Person.lastName, Address.city, Address.state
FROM Person LEFT JOIN Address
ON Person.personId = Address.personId;
