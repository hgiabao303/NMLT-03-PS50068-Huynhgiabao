#include <stdio.h>
int main()
{
    int chon;
    int i;
    int x;
    do
    {
        printf("+-------------------------------------------+\n");
        printf("|          MENU CHUONG TRINH LAB 4.         |\n");
        printf("+-------------------------------------------+\n");
        printf("| 1. Tinh trung binh cac so chia het cho 2  |\n");
        printf("| 2. Kiem tra so nguyen to                  |\n");
        printf("| 3. Kiem tra so chinh phuong               |\n");
        printf("| 4. Thoat truong trinh                     |\n");
        printf("+-------------------------------------------+\n");
        printf("Xin moi chon chuc nang (1 - 4): ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            printf("Ban da chon chuc nang: 1.Tinh trung binh cac so chia het cho 2.\n");
            float min, max;
            int tong = 0;
            int biendem = 0;
            float tbcong = 0;

            printf("Moi ban nhap 2 so nguyen min max:"); // nhập min max
            scanf("%f%f", &min, &max);
            for (int i = min; i <= max; i++)
            {
                if (i % 2 == 0)
                {
                    tong += i;
                    biendem++;
                    printf("%d chia het cho 2\n", i);
                }
            }
            printf("Tong cac so chia het cho 2 la: %d\n", tong);
            printf("Co %d so chia het cho 2\n", biendem);
            if (biendem > 0)
            {
                tbcong = tong / biendem;
                printf("tbcong cac so chia het cho 2 la: %2.f ", tbcong);
            }
            else
            {
                printf("Khong co so nao chia het cho 2 trong khoang [%d den %d]\n", min, max);
            }

            printf("\n");

            break;
        case 2:
            printf("Ban da chon chuc nang: 2.Kiem tra so nguyen to.\n");
            printf("Moi nhap so nguyen x: ");
            scanf("%d", &x);
            if (x < 2)
            {
                printf("%d khong phai là so nguyen to\n", x);
            }
            else
            {

                for (int i = 2; i < x - 1; i++)
                {
                    if (x % i == 0)
                    {
                        break;
                    }
                }
                if (i > x - 1)
                {
                    printf("%d la so nguyen to\n", x);
                }
                else
                {
                    printf("%d khong phai la so nguyen to\n", x);
                }
            }

            break;
        case 3:
            printf("Ban da chon chuc nang: 3.Kiem tra so chinh phuong.\n");
            printf("Moi ban nhap vao 1 so nguyen: ");
            scanf("%d", &x);
            if (x < 1)
            {
                printf("%d khong phai la so chinh phuong\n", x);
            }
            else
            {
                for (int i = 1; i * i <= x; i++)
                {
                    if (i * i == x)
                    {
                        printf("%d la so chinh phuong\n", x);
                        break;
                    }
                }
            }
            if (i * i > x)
            {
                printf("%d khong phai la so chinh phuong\n", x);
            }

            break;
        case 4:
            printf("Ban da chon chuc nang: 4.Thoat truong trinh.\n");
            break;
        default:
            printf("Ban phai chon chuc nang 1 - 4\n");
            break;
        }
    } while (chon != 4);

    return 0;
}
