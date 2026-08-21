void print_customer_data(int target_id) {
  
    printf("Enter Customer ID to view: ");
    scanf("%d", &target_id);
    int found = 0;

    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == target_id) {
            printf("\n============================================\n");
            printf("         CUSTOMER INFORMATION REPORT        \n");
            printf("============================================\n");
            printf(" [ID]      : %d\n", customers[i].id);
            printf(" [Name]    : %s\n", customers[i].name);
            printf(" [Phone]   : %s\n", customers[i].phone);
            printf(" [Balance] : %.2f $\n", customers[i].balance);
            printf("============================================\n");
            
            found = 1;
            break;     
    }

    if (!found) {
        printf("[!] Error: Customer ID %d not found in records.\n", target_id);
    }
}
