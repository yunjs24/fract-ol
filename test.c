#include <stdio.h>
#include <stdlib.h>

void print_bytes(void *ptr, int size) 
{
    unsigned char *p = ptr;
    int i;

	printf("print memory from addr : %p\n", ptr);
    for (i=0; i<size; i++) {
        printf("%02hhX ", p[i]);
		if ((i % 16 == 15))
			printf("\n");
    }
    printf("\n");
}

typedef struct s_point {
	int x;
	int y;
	int z;
} t_point;

int main()
{
	t_point p0;
	t_point p1;
	t_point p2;

	printf("%d, %d, %d\n", p0.x, p0.y, p0.z); // not init
	printf("%d, %d, %d\n", p1.x, p1.y, p1.z); // 
	printf("%d, %d, %d\n", p2.x, p2.y, p2.z); // 
	print_bytes(&p2, 4);
	print_bytes(&p2.x, 4);
	print_bytes(&p2.y, 4);
	print_bytes(&p2.z, 4);
	// print_bytes(&p1, 96);
	// print_bytes(&p2, 96);

	
	// printf("%p, %p, %p\n", &p2->x, &p2->y, &p2->z); // not allocated
	// printf("%p, %p, %p\n", &p3.x, &p3.y, &p3.z); // 

	// print_bytes(&p0, 96);
	// print_bytes(p1, 96);
	// print_bytes(p2, 96);
	// print_bytes(&p3, 96);
}