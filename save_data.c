void save_data() {
    FILE *file = fopen("customers.txt", "w");
     if (file == NULL)
    {
        printf("[!] Error: Could not open file for saving.\n");
        return;
    }
    for(int i=0; i<customer_count; i++) 
        fprintf(file, "%d,%s,%s,%.2f\n", customers[i].id, customers[i].name, customers[i].phone, customers[i].balance);
    fclose(file);
    printf("[ok] Saved.\n");
}
