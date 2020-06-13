#ifndef DEVELOPER_H
#define DEVELOPER_H

typedef struct _Developer Developer;
struct _Developer
{
    char name[100];
    char country[100];
    char mainTechnologies[100];
};

Developer* DeveloperFactory();
void ReadDeveloperData(Developer* developer);
void DesallocateDeveloper(Developer* developer);

#endif