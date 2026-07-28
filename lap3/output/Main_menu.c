#include <stdio.h>
#include <math.h>
int main()
{
    int chon;
    float a;
    do
    {
        printf("+--------------------------------------------------+\n");
        printf("|            MENU CHUONG TRINH LAB 3.              |\n");
        printf("+--------------------------------------------------+\n");
        printf("| 1. Chuc nang tinh hoc luc sinh vien.             |\n");
        printf("| 2. Chuc nang giai phuong trinh bac 2             |\n");
        printf("| 3. Chuc nang tinh tien dien tieu thu hang thang  |\n");
        printf("| 4. Thoat truong trinh                            |\n");
        printf("+--------------------------------------------------+\n");
        printf("Ban hay chon chuc nang (1 - 4): ");
        scanf("%d", &chon); // chon :2
        switch (chon)
        {
        case 1:
        {
            printf("Ban da chon chuc nang: 1.Tinh hoc luc sinh vien.\n");
            // thêm các lệnh

            printf("Moi ban nhap diem: ");
            scanf("%f", &a);
            if (a >= 9)
            {
                printf("Ban dat hoc luc xuat sac"); /* code */
            }
            else
            {
                if (a >= 8)
                {
                    printf("Ban dat hoc luc gioi"); /* code */
                }
                else
                {
                    if (a >= 6.5)
                    {
                        printf("Ban dat hoc luc kha"); /* code */
                    }
                    else
                    {
                        if (a >= 5)
                        {
                            printf("Ban dat hoc luc trung binh");
                        }
                        else
                        {
                            if (a >= 3.5)
                            {
                                printf("Ban dat hoc luc yeu");
                            }
                            else
                            {
                                printf("Ban dat hoc luc kem");
                            }
                        }
                    }
                }
            }
            printf("\n");
            break;
        }
        case 2:
        {

            float a, b, c;
            float x, x1, x2, Delta;
            printf("Ban da chon chuc nang: 2. Giai phuong trinh bac 2.\n");
            printf("Moi ban nhap a,b,c ");
            scanf("%f%f%f", &a, &b, &c);
            if (a == 0)
            {
                printf("Phuong trinh chuyen sang phuong trinh bac nhat");
                if (b == 0 && c == 0)
                {
                    printf("Phuong trinh co vo so nghiem");
                }
                else
                {
                    if (b == 0 && c != 0)
                    {
                        printf("Phuong trinh vo nghiem");
                    }
                    else
                    {

                        x = -c / b;
                        printf("Phuong trinh co nghiem duy nhat x=%.2f", x);
                    }
                }
            }
            else
            {

                Delta = b * b - 4 * a * c;
                if (Delta < 0)
                {
                    printf("Phuong trinh vo nghiem");
                }
                else
                {
                    if (Delta == 0)
                    {
                        x = -b / (2 * a);
                        printf("Phuong trinh co nghiem kep x=%.2f", x);
                    }
                    else
                    {

                        x1 = (-b + sqrt(Delta)) / (2 * a);
                        x2 = (-b - sqrt(Delta)) / (2 * a);
                        printf("Phuong trinh co 2 nghiem rieng biet x1=%.2f\n,x2=%.2f", x1, x2);
                    }
                }
            }
            printf("\n");
            break;
        }
        case 3:
        {
            float ki, td;

            printf("Ban da chon chuc nang: 3. Tinh tien dien .\n");
            printf("Duoi day la bang gia tien dien\n");
            printf("|Bac 1 (Tu 0 den 50 kWh): Gia 1.678 dong/kWh   |\n");
            printf("|Bac 2 (Tu 51 den 100 kWh): Gia 1.734 dong/kWh |\n");
            printf("|Bac 3 (Tu 101 den 200 kWh): Gia 2.014 dong/kWh|\n");
            printf("|Bac 4 (Tu 201 den 300 kWh): Gia 2.536 dong/kWh|\n");
            printf("|Bac 5 (Tu 301 den 400 kWh): Gia 2.834 dong/kWh|\n");
            printf("|Bac 6 (Tu 401 kWh tro len): Gia 2.927 dong/kWh|\n");
            printf("Moi ban nhap so kWh dien thang truoc\n");
            scanf("%f", &ki);
            if (ki <= 50)
            {
                td = ki * 1.678;
                printf("Tien dien thang truoc cua ban la %2.f dong", td);
            }
            else
            {
                if (ki <= 100)
                {
                    td = ki * 1.734;
                    printf("Tien dien thang truoc cua ban la %2.f dong", td);
                }
                else
                {
                    if (ki <= 200)
                    {
                        td = ki * 2.014;
                        printf("Tien dien thang truoc cua ban la %2.f dong", td);
                    }
                    else
                    {
                        if (ki <= 300)
                        {
                            td = ki * 2.536;
                            printf("Tien dien thang truoc cua ban la %2.f dong", td);
                        }
                        else
                        {
                            if (ki <= 400)
                            {
                                td = ki * 2.834;
                                printf("Tien dien thang truoc cua ban la %2.f dong", td);
                            }
                            else
                            {
                                td = ki * 2.927;
                                printf("Tien dien thang truoc cua ban la %2.f dong", td);
                            }
                        }
                    }
                }
            }

            printf("\n");

            break;
        }
        case 4:
            printf("Ban da chon chuc nang: 4. Thoat truong trinh.\n");
            break;
        default:
            printf("Ban phai chon chuc nang 1 - 4\n");
            break;
        }
    } while (chon != 4);

    return 0; 
}
