#include <stdio.h>
    int main() {
        
        double dai, rong;
        
        printf("Nhap chieu dai: ");
        scanf("%lf", &dai);
        printf("Nhap chieu rong: ");
        scanf("%lf", &rong);
        // chu vi dien tich
        printf("chieu dai: %.2f, chieu rong: %.2f\ndien tich: %.2f, chu vi: %.2f", dai, rong, dai * rong, 2 * (dai + rong));

        //tinh chu vi va dien tich hinh tron
        // nhập bán kính
        double r;
        printf("\nNhap ban kinh: ");
        scanf("%lf", &r);
        printf("ban kinh: %.2f\ndien tich: %.2f, chu vi: %.2f", r, 3.14 * r * r, 2 * 3.14 * r);

        return 0;
    }