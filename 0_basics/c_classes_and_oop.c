#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encapsulation and Object-Oriented patterns in C
typedef struct User User;

struct User {
    char fullName[64];
    int birthYear;
    int (*getAge)(const User *self, int currentYear);
    void (*displayInfo)(const User *self, int currentYear);
};

static int user_get_age(const User *self, int currentYear) {
    return currentYear - self->birthYear;
}

static void user_display_info(const User *self, int currentYear) {
    printf("User: %s | Birth Year: %d | Age: %d\n",
           self->fullName, self->birthYear, self->getAge(self, currentYear));
}

User user_create(const char *name, int year) {
    User u;
    strncpy(u.fullName, name, sizeof(u.fullName) - 1);
    u.fullName[sizeof(u.fullName) - 1] = '\0';
    u.birthYear = year;
    u.getAge = user_get_age;
    u.displayInfo = user_display_info;
    return u;
}

int main(void) {
    printf("=== Object-Oriented Patterns & Struct Methods in C ===\n");
    User u1 = user_create("Alice Smith", 1995);
    User u2 = user_create("Bob Johnson", 2001);

    int currentYear = 2026;
    u1.displayInfo(&u1, currentYear);
    u2.displayInfo(&u2, currentYear);
    return 0;
}
