#include<stdio.h>
#include<stdlib.h>

struct student 
{
    char name[10];
    int age;
    float score;
}stu[2];

int main() 
{
    printf("please input name age score:\n");
    for(int i = 0; i < 2; i++) {
        scanf("%s %d %f", &stu[i].name, &stu[i].age, &stu[i].score);
    }

    FILE* fp;
    if((fp = fopen("hello.dat", "w+")) == NULL)
    {
        printf("fopen failed\n");
        return -1;
    }

    fwrite(&stu, sizeof(struct student), 2, fp);
    if(ferror(fp) != 0) 
    {
        printf("fwrite failed!\n");
        clearerr(fp);
        return -1;
    }
    fflush(fp);
    rewind(fp);

    struct student* buf = (struct student*)malloc(2* sizeof (struct student));
    fread(buf, sizeof (struct student), 2, fp);
    if(ferror(fp) != 0)
    {
        printf("read failed\n");
        clearerr(fp);
        return -1;
    }
    printf("姓名\t年龄\t分数\n");
    for(int i = 0; i < 2; i++) 
    {
        printf("%s\t%d\t%f\n", stu[i].name, stu[i].age, stu[i].score);
    }
    fclose(fp);
    free(buf);
    buf = NULL;
    return 0;
}
