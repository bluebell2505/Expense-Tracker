#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

struct Expense {
    double amount;
    string category;
};

vector<Expense> expenses;

// Function to add a new expense
void addExpense() {
    Expense expense;
    cout << "Enter expense amount: ";
    cin >> expense.amount;
    cout << "Enter expense category (e.g., food, rent): ";
    cin.ignore(); // Clear input buffer
    getline(cin, expense.category);
    expenses.push_back(expense);
    cout << "Expense added successfully!" << endl;
}

// Function to display all expenses
void showExpenses() {
    if (expenses.empty()) {
        cout << "No expenses recorded yet." << endl;
        return;
    }
    cout << "Expenses:\n";
    cout << "Amount\tCategory\n";
    cout << "-------\t---------\n";
    for (const Expense& expense : expenses) {
        cout << expense.amount << "\t" << expense.category << endl;
    }
}

// Function to calculate total expenses
double getTotalExpenses() {
    double total = 0;
    for (const Expense& expense : expenses) {
        total += expense.amount;
    }
    return total;
}

int main() {
    int choice;

    while (true) {
    cout << "\nExpense Tracker Menu:\n";
    cout << "1. Add Expense\n";
    cout << "2. Show Expenses\n";
    cout << "3. Total Expenses\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addExpense();
        break;
        case 2:
            showExpenses();
        break;
        case 3:
            cout << "Total Expenses: " << getTotalExpenses() << endl;
        break;
        case 4:
            cout << "Exiting program..." << endl;
            return 0;
        default:
        cout << "Invalid choice. Please try again." << endl;
    }
    }

    return 0;
}
