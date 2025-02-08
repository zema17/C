#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

Contact contacts[MAX_CONTACTS];
int count = 0;

void addContact() {
    if (count >= MAX_CONTACTS) {
        printf("Danh bạ đầy, không thể thêm!\n");
        return;
    }
    printf("Nhập tên: ");
    scanf(" %[^\n]", contacts[count].name);
    printf("Nhập số điện thoại: ");
    scanf(" %s", contacts[count].phone);
    count++;
    printf("Đã thêm thành công!\n");
}

void deleteContact() {
    char name[50];
    printf("Nhập tên cần xóa: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Đã xóa liên hệ thành công!\n");
            return;
        }
    }
    printf("Không tìm thấy tên trong danh bạ.\n");
}

void displayContacts() {
    if (count == 0) {
        printf("Danh bạ trống.\n");
        return;
    }
    printf("\nDanh sách liên hệ:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Quản lý Danh Bạ ---\n");
        printf("1. Thêm liên hệ\n");
        printf("2. Xóa liên hệ\n");
        printf("3. Hiển thị danh bạ\n");
        printf("4. Thoát\n");
        printf("Chọn chức năng: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: deleteContact(); break;
            case 3: displayContacts(); break;
            case 4: printf("Thoát chương trình.\n"); return 0;
            default: printf("Chọn sai, vui lòng nhập lại.\n");
        }
    }
}
