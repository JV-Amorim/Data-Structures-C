#include <stdio.h>
#include <stdlib.h>
#include "developer.h"

Developer* DeveloperFactory()
{
    Developer* newDeveloper = malloc(sizeof(Developer));

    printf("Type the developer name: ");
    scanf("%s", newDeveloper->name);
    fflush(stdin);

    printf("Type the developer country: ");
    scanf("%s", newDeveloper->country);
    fflush(stdin);

    printf("Type the developer main technologies: ");
    scanf("%s", newDeveloper->mainTechnologies);
    fflush(stdin);

    return newDeveloper;
}

void ReadDeveloperData(Developer* developer)
{
    if (developer != NULL)
    {
        printf("Name: %s \n", developer->name);
        printf("Country: %s \n", developer->country);
        printf("Main technologies: %s \n", developer->mainTechnologies);
    }
}

void DesallocateDeveloper(Developer* developer)
{
    free(developer);
}