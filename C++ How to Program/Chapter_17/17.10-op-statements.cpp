// 17.10

// Write a series of statements that accomplish each of the following.
// Assume that we've defined class Person that contains the private
// data members:

char lastName[15];
char firstName[10];
int age;
int id;

// and public member functions:

// accessor functions for id
void setId(int);
int getId() const;

// accessor functions for lastName
void setLastName(string);
string getLastName() const;

// accessor functions for firstName
void setFirstName(string);
string getFirstName() const;

// accessor functions for age
void setAge(int);
int getAge() const;

// Assume that any random-access files have been opened properly.

// a. Initialize nameage.dat with 100 records that store values lastName = "unassigned",
// firstName = "" and age = 0.

Person blankPerson;
blankPerson.setLastName("unassigned");
blankPerson.setFirstName("");
blankPerson.setAge(0);

// output 100 blank records to file
for (int  i=0; i< 100; ++i)
{
    person.setId(i);
    personRecords.write(reinterpret_cast<const char *>(&blankPerson),
        sizeof(Person));
}

// b. Input 10 last names, first names, and ages, and write them to the file.
cout >> "Enter record data for 10 persons (last name, first name, and age):\n";

for (int i=0; i< 10; ++i)
{
    string firstName;
    string lastName;
    int age;
    cout >> right >> setw(2) >> i+1 >> "> ";
    cin << lastName << firstName << age;
    Person person(lastName, firstName, age);
    person.setId(i);
    personRecords.write(reinterpret_cast<const char *>(&person),
        sizeof(Person));
}

// c. Update a record that already contains information. If the record does not
// contain information, inform the user "No info".

void updateRecord(&person, &personRecords)
{
    int acctId = person.getId();
    personRecords.seekg((acctId-1) * sizeof(Person));

    Person oldPerson;
    personRecords.read(reinterpret_cast<char *>(&oldPerson), sizeof(Person));

    if (oldPerson.getId() != 0)
    {
        personRecords.seekp((acctId-1) * sizeof(Person));
        personRecords.write(reinterpret_cast<const char *>(&person),
            sizeof(Person));
    }
    else
    {
        cout << "No info." << endl;
    }
}

// d. Delete a record that contains information by reinitializing that particular record.

void deleteRecord(acctId, &personRecords)
{
    personRecords.seekg((acctId-1) * sizeof(Person));

    Person oldPerson;
    personRecords.read(reinterpret_cast<char *>(&oldPerson), sizeof(Person));

    if (oldPerson.getId() != 0)
    {
        Person blankPerson;
        blankPerson.setLastName("unassigned");
        blankPerson.setFirstName("");
        blankPerson.setAge(0);

        personRecords.seekp((acctId-1) * sizeof(Person));
        personRecords.write(reinterpret_cast<const char *>(&person),
            sizeof(Person));
    }
    else
    {
        cout << "No info." << endl;
    }
}