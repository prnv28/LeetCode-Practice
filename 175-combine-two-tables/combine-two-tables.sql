Select firstname, lastname, city, state from Person 
left join  Address 
On Person.personId=Address.personId;