# Selection Sort

Bài toán: Thuật toán sắp xếp chọn

Thuật toán selection sort cũng là một trong những thuật toán đơn giản.

Yêu cầu: Hãy cài đặt thuật toán sắp selection sort để sắp xếp lại tăng dần mảng có N phần tử. Trong lúc chạy thuật toán, nếu xảy ra hành động swap, hãy in ra mảng sau hành động swap đó. Bằng cách này, các bạn có thể hình dung được cách hoạt động của thuật toán sắp xếp.

Lưu ý: swap xảy ra nếu vị trí của phần tử nhỏ nhất khác vị trí của phần tử đang xét i

Input:

Dòng đầu tiên là số nguyên N dương (0 < N < 200)

Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng

Output:

Các dòng tiếp theo in ra cấu hình của mảng A mỗi lần mảng A xảy ra hành động swap.

---

# Selection Sort Trace

Input
Dòng đầu tiên là số nguyên N dương (0 < N < 200)

Dòng tiếp theo chứa N số nguyên (với giá trị mỗi số nguyên nhỏ hơn 2 * 10^9) là các phần tử của mảng A

Output
In ra màn hình theo mẫu ví dụ :
Mang truoc khi sap xep:
3 0 8 2 1 4 7

Sap xep:
i = 0
Mang truoc khi swap: 3 0 8 2 1 4 7
Phan tu nho nhat trong doan [1, 6]: 0
Swap 3 va 0
Mang sau khi swap: 0 3 8 2 1 4 7

i = 1
Mang truoc khi swap: 0 3 8 2 1 4 7
Phan tu nho nhat trong doan [2, 6]: 1
Swap 3 va 1
Mang sau khi swap: 0 1 8 2 3 4 7

i = 2
Mang truoc khi swap: 0 1 8 2 3 4 7
Phan tu nho nhat trong doan [3, 6]: 2
Swap 8 va 2
Mang sau khi swap: 0 1 2 8 3 4 7

i = 3
Mang truoc khi swap: 0 1 2 8 3 4 7
Phan tu nho nhat trong doan [4, 6]: 3
Swap 8 va 3
Mang sau khi swap: 0 1 2 3 8 4 7

i = 4
Mang truoc khi swap: 0 1 2 3 8 4 7
Phan tu nho nhat trong doan [5, 6]: 4
Swap 8 va 4
Mang sau khi swap: 0 1 2 3 4 8 7

i = 5
Mang truoc khi swap: 0 1 2 3 4 8 7
Phan tu nho nhat trong doan [6, 6]: 7
Swap 8 va 7
Mang sau khi swap: 0 1 2 3 4 7 8

Mang sau khi sap xep:
0 1 2 3 4 7 8

---

# Insertion Sort Trace

Input
Dong dau tien la so nguyen N duong (0 < N < 200)

Dong tiep theo chua N so nguyen (voi gia tri moi so nguyen nho hon 2 * 10^9) la cac phan tu cua mang A

Output
In ra man hinh theo mau vi du:
Mang truoc khi sap xep:
3 0 8 2 1 4 7

Sap xep:
i = 1
Mang truoc khi xu ly: 3 0 8 2 1 4 7
Phan tu dang xet A[1] = 0
Chen 0 vao vi tri k = 0
Mang sau khi xu ly: 0 3 8 2 1 4 7

...