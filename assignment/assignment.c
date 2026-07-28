#include <stdio.h>
int main()
{
    int chon;
    do
    {
        printf("+--------------------------------------------------------------+\n");
        printf("|                    MENU CHUONG TRINH ASM                     |\n");
        printf("+--------------------------------------------------------------+\n");
        printf("| 0. Kiem tra so nguyen                                        |\n");
        printf("| 1. Tim uoc so chung va boi so chung cua 2 so                 |\n");
        printf("| 2. Chuong trinh tinh tien cho quan Karaoke                   |\n");
        printf("| 3. Tinh tien dien                                            |\n");
        printf("| 4. Xay dung chuc nang tinh lai suat vay ngan hang vay tra gop|\n");
        printf("| 5. Sap xep thong tin sinh vien                               |\n");
        printf("| 6. Xay dung chuong trinh tinh toan phan so                   |\n");
        printf("| 7. Thoat truong trinh                                        |\n");
        printf("+--------------------------------------------------------------+\n");
        printf("Ban hay chon chuc nang (0 - 7): ");
        scanf("%d", &chon); // chon :2
        switch (chon)
        {
        case 0:
            printf("Ban da chon chuc nang: 0. Kiem tra so nguyen .\n");
            // thêm các lệnh
            break;
        case 1:
            printf("Ban da chon chuc nang: 1. Tim uoc so chung và boi so chung cua 2 so.\n");
            break;
        case 2:
            printf("Ban da chon chuc nang: 2. Chương trinh tinh tien cho quan Karaoke .\n");
            break;
        case 3:
            printf("Ban da chon chuc nang: 3. Tinh tien dien.\n");
            break;
        case 4:
            printf("Ban da chon chuc nang: 4. Xay dung chuc nang tinh lai suat vay ngan hang vay tra gop.\n");
            break;
        case 5:
            printf("Ban da chon chuc nang: 5. Sap xep thong tin sinh vien.\n");
            break;
        case 6:
            printf("Ban da chon chuc nang: 6. Xay dung chuong trinh tinh toan phan so.\n");
            break;
        case 7:
            printf("Ban da chon chuc nang: 7. Thoat truong trinh .\n");
            break;
        default:
            printf("Ban phai chon chuc nang 0 - 7\n");
            break;
        }
    } while (chon != 7);

    return 0;
}
