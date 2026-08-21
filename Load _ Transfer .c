int load_data(Customer customers[]) {
    FILE *file = fopen("customers.txt", "r");
    if (file == NULL) {
        printf("No existing database found. Starting fresh.\n");
        return 0;
    }

    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        
        int parsed = sscanf(line, "%d %s %s %f", 
                            &customers[count].id, 
                            customers[count].name, 
                            customers[count].phone, 
                            &customers[count].cash);

        if (parsed == 4) {
            count++;
        }
    }

    fclose(file);
    printf("Successfully loaded %d customer(s).\n", count);
    return count;
}


void transfer_money(Customer customers[], int count) {
    int sender_id, receiver_id;
    float amount;

    printf("Enter Sender ID: ");
    scanf("%d", &sender_id);
    printf("Enter Receiver ID: ");
    scanf("%d", &receiver_id);

    if (sender_id == receiver_id) {
        printf("Error: Sender and Receiver IDs cannot be the same!\n");
        return;
    }

    int sender_index = -1, receiver_index = -1;
    for (int i = 0; i < count; i++) {
        if (customers[i].id == sender_id) sender_index = i;
        if (customers[i].id == receiver_id) receiver_index = i;
    }

    if (sender_index == -1) {
        printf("Error: Sender ID not found!\n");
        return;
    }
    if (receiver_index == -1) {
        printf("Error: Receiver ID not found!\n");
        return;
    }

    printf("Enter Amount to Transfer: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Error: Amount must be greater than zero!\n");
    } else if (customers[sender_index].cash < amount) {
        printf("Error: Insufficient cash in sender account!\n");
    } else {
        customers[sender_index].cash -= amount;
        customers[receiver_index].cash += amount;
        printf("Transfer successful!\n");
        printf("Sender New Cash Balance: %.2f\n", customers[sender_index].cash);
    }
}
