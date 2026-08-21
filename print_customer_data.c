void print_customer_data(int target_id) {
    int found = 0;
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == target_id) {
            printf("\n--- ID: %d | Name: %s | Phone: %s | Balance: %.2f ---\n", 
                   customers[i].id, customers[i].name, customers[i].phone, customers[i].balance);
            found = 1; break;
        }
    }
    if (!found) printf("[!] Error: ID %d not found.\n", target_id);
}