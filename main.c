#include <stdio.h>
#include <stdlib.h>

#include "list.h"


struct student {
	int data;
	char name[50];

	struct list_head node;
};

struct list_head head;

void print(void)
{
	struct student *stu;
	list_for_each_entry(stu, &head, node) {
		printf("data:%d name:%s\n", stu->data, stu->name);
	}

}
void delete(void)
{
	struct student *stu;
	int n;
	scanf("%d",&n);
	list_for_each_entry(stu, &head, node) {
		if (stu->data == n) {
			list_del(&stu->node);
			free(stu);
			stu = NULL;
			return;
		}
	}

}
void add(void)
{
	struct student *stu;

	stu = malloc(sizeof(*stu));

	scanf("%d %s", &stu->data, stu->name);
	list_add_tail(&stu->node, &head);
}

int search(void)
{
	struct student *stu;
	int n;
	scanf("%d",&n);
	list_for_each_entry(stu, &head, node) {
		if (stu->data == n) {
			printf("data:%d name:%s\n", stu->data, stu->name);
			return 0;
		}
	}

	return -1;
}


int main(int argc, const char *argv[])
{
	int x=0;
	while (1) {
		printf("create:1 print:2 delete:3 add:4 search:5 exit:0\n");
		scanf("%d",&x);
		switch (x) {
			case 1:
				INIT_LIST_HEAD(&head);
				break;
			case 2:
				print();
				break;
			case 3:
				delete();
				break;
			case 4:
				add();
				break;
			case 5:
				x = search();
				if(x < 0)
					printf("not search!\n");
				break;
			default:
				return 0;
		}

	}

	return 0;
}
