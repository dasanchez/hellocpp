// 17.8: File Matching

// Write a complete file-matching accounts receivable program.
// The account data will include the customer's name, balance, and account number.
// Use the account number on each file as the record key for matching purposes.
// Assume that each file is a sequential file with records stored in increasing order
// by account number.
// As transactions occur (e.g., sales are made and cash payments arrive), they're entered
// into a file. At the end of each business period, the file of transactions (trans.dat)
// is applied to the master file (oldmast.dat), thus updating each account's record of
// purchases and payments. During an updating run, the master file is rewritten as a new
// file (newmast.dat), which is then used at the end of the next business period to
// begin the updating process again.
// When a match occurs (i.e., records with the same accounnt number appear on both
// the master and transaction files), add the dollar amount on the transaction file to
// the current balance on the master file, and write the newmast.dat record.
// When there is a master record for a particular account but no corresponding transaction
// record, merely write the master record to newmast.dat.
// When there is a transaction record but no corresponding master record, print
// the error message "Unmatched transaction record for account number [acct #]".

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
                break;
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