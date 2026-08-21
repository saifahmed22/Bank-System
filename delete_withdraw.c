void delete_customer() {
    int target_id;
    printf("Enter Customer ID to delete: ");
    scanf("%d", &target_id);

    int found_index = -1;

    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == target_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Customer with ID %d not found!\n", target_id);
        return;
    }

    for (int i = found_index; i < customer_count - 1; i++) {
        customers[i] = customers[i + 1];
    }

    customer_count--;
    printf("Customer deleted successfully!\n");
}

void withdraw() {
    int target_id;
    float amount;
    
    printf("Enter Customer ID: ");
    scanf("%d", &target_id);

    int found_index = -1;

    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == target_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Customer not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (customers[found_index].cash < amount) {
        printf("Error: Insufficient balance! (Current balance: %.2f)\n", customers[found_index].cash);
    } else {
        customers[found_index].cash -= amount;
        printf("Withdrawal successful! Remaining balance: %.2f\n", customers[found_index].cash);
    }
}
