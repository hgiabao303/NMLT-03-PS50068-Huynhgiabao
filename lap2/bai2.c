#include <stdio.h>
int main() {    
    // Nhu cầu nhập: điểm toán, lý, hóa
    int toan, ly, hoa;
    printf("Nhap diem toan, ly, hoa: ");
    scanf("%d %d %d", &toan, &ly, &hoa);
     float diemTB = (toan*3 + ly*2 + hoa) / 6;
     printf("toan: %d\nly: %d\nhoa: %d\ndiem trung binh: %.2f", toan, ly, hoa, diemTB);
    return 0;
}

            

