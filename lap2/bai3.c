#include<stdio.h>
int main() {
    int a,b;
    float x;
    printf("nhap  a, b: ");
    scanf("%d%d",&a ,&b);
    x = -(float) b/a;
    printf("phuong trinh %dx + %d =0 co nghiem la: %.2f" ,a,b,x);
    return 0;}
    
