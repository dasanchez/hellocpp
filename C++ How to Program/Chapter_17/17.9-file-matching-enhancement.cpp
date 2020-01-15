// 17.9: File Matching Enhancement

// It's common to have several transaction records with the same record key, because
// a particular customer might make several purchases and cash payments during
// a business period. Rewrite the program fom exercise 17.8 to provide for the
// possibility of handling several transaction records with the same record key.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void outputLine(ostream &);
void printAccounts(ifstream &);
void matchTransactions(ifstream &, ifstream &, ofstream &);

int main()
{

    // create stream objects for oldmast.dat, trans.dat, and newmast.dat
    ifstream inOldMaster("oldmast.dat", ios::in);

    // end program if program cannot open file
    if (!inOldMaster)
    {
        cerr << "oldmast.dat could not be opened." << endl;
        exit(1);
    } // end if
    else
    {
        cout << "Reading old balances from oldmast.dat" << endl;
    }

    ifstream inTransaction("trans.dat", ios::in);

    // end program if program cannot open file
    if (!inTransaction)
    {
        cerr << "trans.dat could not be opened." << endl;
        exit(1);
    } // end if
    else
    {
        cout << "Reading transactions from trans.dat" << endl;
    }

    ofstream outNewMaster("newmast.dat", ios::out);
    // end program if program cannot open file
    if (!outNewMaster)
    {
        cerr << "newmast.dat could not be created." << endl;
        exit(1);
    } // end if
    else
    {
        cout << "Saving new balances to newmast.dat" << endl;
    }

    matchTransactions(inOldMaster, inTransaction, outNewMaster);

    ifstream inNewMaster("newmast.dat", ios::in);
    printAccounts(inNewMaster);
}

void printAccounts(ifstream &readFromFile)
{
    cout << left << setw(10) << "Account" << setw(16)
         << "First Name" << setw(16) << "Last Name" << right
         << setw(12) << "Balance" << endl;

    char temp[100];
    readFromFile.getline(temp, 100);

    while (!readFromFile.eof())
    {
        int accountNumber = -1;
        string firstName;
        string lastName;
        double balance;
        // print single record out
        readFromFile >> accountNumber >> firstName >> lastName >> balance;

        if (accountNumber >= 0)
        {
            cout << left << setw(10) << accountNumber << setw(16)
                 << firstName << setw(16) << lastName << right
                 << setw(12) << setprecision(2) << fixed << balance << endl;
        }
    } // end while
    readFromFile.clear();
    readFromFile.seekg(0);
} // end printAccounts

void matchTransactions(ifstream &oldMaster, ifstream &transactions, ofstream &newMaster)
{
    // Iterate through the entire old master file,
    // if there are transactions matching an existing account, apply them
    // before outputting them to the new master.

    newMaster << left << setw(10) << "Account" << setw(16)
              << "First Name" << setw(16) << "Last Name" << right
              << setw(12) << "Balance" << endl;

    while (!oldMaster.eof())
    {
        int masterAccount;
        string firstName;
        string lastName;
        double oldBalance;
        oldMaster >> masterAccount >> firstName >> lastName >> oldBalance;

        // check if there are any transactions against this account
        double newBalance = oldBalance;
        while (!transactions.eof())
        {
            int transAccount;
            double transaction;
            transactions >> transAccount >> transaction;
            if (transAccount == masterAccount)
            {
                // account exists
                newBalance += transaction;
                cout << "Adding " << transaction << " to account " << transAccount << endl;
            }
            else if (transAccount > masterAccount)
            {
                // assuming a sequential file, there are no transactions for this account
                break;
            }
        }
        transactions.clear();  // reset eof
        transactions.seekg(0); // reposition to beginning of file

        newMaster << left << setw(10) << masterAccount << setw(16)
                  << firstName << setw(16) << lastName << right
                  << setw(12) << fixed << setprecision(2) << newBalance << endl;
    }

    newMaster.close();

    // get the old master and transactions files ready for a second pass
    oldMaster.clear();
    oldMaster.seekg(0);

    while (!transactions.eof())
    {
        // print mismatches in account numbers (transactions for non-existing accounts)
        int transAcct;
        double transaction;
        bool accountExists = false;

        transactions >> transAcct >> transaction;

        while (!oldMaster.eof())
        {
            int masterAcct;
            string firstName;
            string lastName;
            double oldBalance;
            oldMaster >> masterAcct >> firstName >> lastName >> oldBalance;

            if (masterAcct == transAcct)
            {
                accountExists = true;
                break;
            }
            else if (masterAcct > transAcct)
            {
                break;
            }
        }
        oldMaster.clear();
        oldMaster.seekg(0);
        if (!accountExists)
            cout << "*** Unmatched transaction record number for account number "
                 << transAcct << " ***" << endl;
    }
}