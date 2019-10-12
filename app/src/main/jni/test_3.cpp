#include <stdio.h>

//结构体
struct stu{
 	int age;
	char* name;  //非基础数据类型都要使用指针,指向引用数据类型(对象)的内存地址
	int num;
	float score;
}student0;


int main()
{

   student0.name = "aa";
   printf("%s\n",student0.name);

   struct stu student1,student2;

   student1.age = 20;
   student1.name = "zhoguang";
   student1.num = 2007112219;
   student1.score = 98.1;

   printf("%d,%s,%d,%.1f\n",student1.age,student1.name,student1.num,student1.score);

   student2.name="bb";
   printf("%s\n",student2.name);

   return 0;
}
