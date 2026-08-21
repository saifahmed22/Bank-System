int save_data(Customer customers[], int count) {

    if (count < 0) {
        printf("[!] Critical Error: Invalid record count.\n");
        return 0;
    }
    
    FILE *file = fopen("customers.txt", "w");
    if (file == NULL) {
        printf("[!] Error: Could not open file (Access Denied).\n");
        return 0;
    }
    int saved_count = 0;
    for (int i = 0; i < count; i++) {
        
        if (customers[i].id <= 0) {
            printf("[!] Warning: Corrupted ID found for record %d. Skipping...\n", i);
            continue; 
        }
        
        int written = fprintf(file, "%d,%s,%s,%.2f\n", 
                              customers[i].id, 
                              customers[i].name, 
                              customers[i].phone, 
                              customers[i].cash);
        
        if (written > 0) {
            saved_count++;
        }
    }
    //  الحماية عند الإغلاق 
    if (fclose(file) != 0) {
        printf("[!] Error: Failed to close the file properly (Data might be incomplete).\n");
        return 0;
    }
    
    if (saved_count == count) {
        printf("[✓] Success: %d records saved securely.\n", saved_count);
        return 1;
    } else {
        printf("[!] Warning: Only %d/%d records were saved safely.\n", saved_count, count);
        return 0;
    }
} 