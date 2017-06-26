#include <stdio.h>
#include <string.h>
struct students
{
    char name;
    int age;
};

int main(void)
{
    struct student s1;
    strcpy(s1.name, "jack");
    s1.age = 10;
    printf("s1.name = %s, s1.age = %d\n", s1.name, s1.age);
    return 0;
}

