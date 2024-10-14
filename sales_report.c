#include <stdio.h>
#define num_months 12 // defines number of months in a year (12)

// array of each month for easy access
const char* months[num_months] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// function to create and print monthly sales report
void monthly_sales_report(float sales[]) {
    printf("Monthly sales report for 2024:\n");
    printf("%-10s %-10s\n", "Month:", "Sales:");
     //%-10s left-alignes using "-", and "10" creates a minimum width so that it prints cleanly
    for (int i = 0; i < num_months; i++) {
        printf("%-10s %-10.2f\n", months[i], sales[i]);
    }
}

// function to create and print sales summary report
void sales_summary_report(float sales[]) {
    float min = sales[0], max = sales[0], sum = 0.0;
    int min_month = 0, max_month = 0;

    for (int i = 0; i < num_months; i++) {
        if (sales[i] < min) {
            min = sales[i];
            min_month = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            max_month = i;
        }
        sum += sales[i];
    }

    printf("\nSales Summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[min_month]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[max_month]);
    printf("Average sales: $%.2f\n", sum / num_months);
}

// function to create and print the six month report
void six_month_moving_average(float sales[]) {
    printf("\nSix-Month Moving Average Report:\n");

    for (int i = 0; i <= num_months - 6; i++) {
        float sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%-10s - %-10s %.2f\n", months[i], months[i + 5], sum / 6);
    }
}

// function to create and print the sales report
void sales_report(float sales[], float sorted_sales[], int sorted_months[]) {
    // Copy sales data to another array
    for (int i = 0; i < num_months; i++) {
        sorted_sales[i] = sales[i];
        sorted_months[i] = i;  // keeps track of original month indices
    }

    // bubble sort in descending order, while also sorting months accordingly
    for (int i = 0; i < num_months - 1; i++) {
        for (int j = 0; j < num_months - i - 1; j++) {
            if (sorted_sales[j] < sorted_sales[j + 1]) {
                // swap sales values
                float temp_sales = sorted_sales[j];
                sorted_sales[j] = sorted_sales[j + 1];
                sorted_sales[j + 1] = temp_sales;

                // swap corresponding months
                int temp_month = sorted_months[j];
                sorted_months[j] = sorted_months[j + 1];
                sorted_months[j + 1] = temp_month;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-10s %-10s\n", "Month", "Sales");
    for (int i = 0; i < num_months; i++) {
        printf("%-10s $%-10.2f\n", months[sorted_months[i]], sorted_sales[i]);
    }
}

int main() {
    float sales[num_months], sorted_sales[num_months];
    int sorted_months[num_months];

    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    for (int i = 0; i < num_months; i++) {
        if (fscanf(input_file, "%f", &sales[i]) != 1) {
            printf("Error reading sales data.\n");
            fclose(input_file);
            return 1;
        }
    }
    fclose(input_file);

    // call functions
    monthly_sales_report(sales);
    sales_summary_report(sales);
    six_month_moving_average(sales);
    sales_report(sales, sorted_sales, sorted_months);

    return 0;
}