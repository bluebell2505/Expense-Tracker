#include <stdio.h>
#include <stdlib.h>

struct Expense 
{
	double amount;
	char category[50]; 
};

void addExpense(struct Expense* expenses, int* numExpenses) 
{
  // Reallocate memory if needed
	if (*numExpenses == 0) 
	{
		expenses = (struct Expense*)malloc(sizeof(struct Expense));
		if (expenses == NULL) 
		{
			printf("Memory allocation failed!\n");
			return;
		}
	} 
	else 
	{
		expenses = (struct Expense*)realloc(expenses, (*numExpenses + 1) * sizeof(struct Expense));
		if (expenses == NULL) 
		{
			printf("Memory allocation failed!\n");
			return;
		}
	}

	printf("Enter expense amount: ");
	scanf("%lf", &expenses[*numExpenses].amount);
	printf("Enter expense category (e.g., food, rent): ");
	scanf(" %[^\n]", expenses[*numExpenses].category); // to read until newline
	(*numExpenses)++;

	printf("Expense added successfully!\n");
}

void showExpenses(struct Expense* expenses, int numExpenses) 
{
	if (numExpenses == 0) 
	{
		printf("No expenses recorded yet.\n");
		return;
	}
	printf("Expenses:\n");
	printf("Amount\tCategory\n");
	printf("-------\t---------\n");
	for (int i = 0; i < numExpenses; i++) 
	{
		printf("%lf\t%s\n", expenses[i].amount, expenses[i].category);
	}
}

double getTotalExpenses(struct Expense* expenses, int numExpenses) 
{
	double total = 0;
	for (int i = 0; i < numExpenses; i++) 
	{
		total += expenses[i].amount;
	}
	return total;
}

int main() 
{
	struct Expense* expenses = NULL;
	int numExpenses = 0;

	int choice;

	while (1) {
		printf("\nExpense Tracker Menu:\n");
		printf("1. Add Expense\n");
		printf("2. Show Expenses\n");
		printf("3. Total Expenses\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

    switch (choice) {
		case 1:
			addExpense(expenses, &numExpenses);
			break;
		case 2:
			showExpenses(expenses, numExpenses);
			break;
		case 3:
			printf("Total Expenses: %lf\n", getTotalExpenses(expenses, numExpenses));
			break;
		case 4:
			printf("Exiting program...\n");
			free(expenses); // Free allocated memory
			return 0;
		default:
			printf("Invalid choice. Please try again.\n");
		}
	}

	return 0;
}
