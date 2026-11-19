#include <stdio.h>
#include <string.h>

struct Address{
    char city[50];
    char district[50];
    int postalCode;
};
struct Patient{
    int id;
    char name[50];
    int age;
    char disease[50];
    struct Address addr;
};
void displayPatient(struct Patient p)
{
    printf("ID: %d | Name: %s | Age: %d | Disease: %s | Address: %s, %s - %d\n",
           p.id, p.name, p.age, p.disease, p.addr.city, p.addr.district,
           p.addr.postalCode);
}
int main()
{
    struct Patient p[5];
    char searchDistrict[50];
    for (int i = 0; i < 5; i++){
        printf("\nEnter details for Patient %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &p[i].id);

        printf("Name: ");
        scanf(" %[^\n]", p[i].name);

        printf("Age: ");
        scanf("%d", &p[i].age);

        printf("Disease: ");
        scanf(" %[^\n]", p[i].disease);

        printf("City: ");
        scanf(" %[^\n]", p[i].addr.city);

        printf("District: ");
        scanf(" %[^\n]", p[i].addr.district);

        printf("Postal Code: ");
        scanf("%d", &p[i].addr.postalCode);
    }
    printf("\n--- All Patient Records ---\n");
    for (int i = 0; i < 5; i++){
        displayPatient(p[i]);
    }
    printf("\n--- Patients Older Than 60 ---\n");
    for (int i = 0; i < 5; i++){
        if (p[i].age > 60)
        {
            displayPatient(p[i]);
        }
    }
    printf("\nEnter District to scarch: ");
    scanf(" %[^\n]", searchDistrict);

    printf("\n--- Patients in District: %s ---\n", searchDistrict);
    for (int i = 0; i < 5; i++){
        if (strcmp(p[i].addr.district, searchDistrict) == 0){
            displayPatient(p[i]);
        }  
    }
    return 0;
}

        
