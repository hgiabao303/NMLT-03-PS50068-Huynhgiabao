#include <stdio.h>
#include <string.h>

int main() {
    char mssv[20];
    char hoTen[100];
    int namSinh;
    int tuoi;
    float diemTB;

    // 1. Nhập Mã số sinh viên
    printf("Nhap ma so sinh vien: ");
    scanf("%19s", mssv);
    while (getchar() != '\n'); // Xóa bộ nhớ đệm để không bị trôi lệnh nhập tiếp theo

    // 2. Nhập Họ và Tên (cho phép chứa dấu cách)
    printf("Nhap ho va ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0'; // Xóa ký tự xuống dòng thừa ở cuối chuỗi

    // 3. Nhập Năm sinh
    printf("Nhap nam sinh: ");
    scanf("%d", &namSinh);

    // 4. Nhập Điểm trung bình
    printf("Nhap diem trung binh: ");
    scanf("%f", &diemTB);

    // Tính toán tuổi tự động theo mốc năm 2026
    tuoi = 2026 - namSinh;

    // Xuất dữ liệu ra màn hình theo đúng định dạng yêu cầu
    printf("\nMa so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoTen);
    printf("Nam sinh: %d\n", namSinh);
    printf("Tuoi: %d\n", tuoi);
    printf("Diem Trung Binh: %.2f\n", diemTB);

    return 0;
}
