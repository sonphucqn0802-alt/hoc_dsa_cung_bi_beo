# Danh sách liên kết đơn

Thư mục này chứa các bài tập cơ bản về danh sách liên kết đơn trong C++.

## Các file bài tập
- `AddTail.cpp` — Thêm phần tử vào cuối danh sách liên kết.
- `AddHead.cpp` — Thêm phần tử vào đầu danh sách liên kết.
- `DeleteHead.cpp` — Xóa K phần tử đầu của danh sách.
- `DeleteTail.cpp` — Xóa K phần tử cuối của danh sách.
- `DeleteNode.cpp` — Tìm và xóa nút có giá trị K.
- `SearchHead.cpp` — Tìm vị trí xuất hiện đầu tiên của phần tử K.
- `ReverseTheList.cpp` — Đảo ngược danh sách liên kết.
- `SortWSelectionSort.cpp` — Sắp xếp danh sách bằng Selection Sort.
- `SelectionSortPointerVer.cpp` — Sắp xếp danh sách bằng Selection Sort với hoán đổi con trỏ.
- `Merge2LinkedList.cpp` — Nối hai danh sách liên kết L2 vào sau L1.
- `MergeTwoAlreadyOrderedLinkedLists.cpp` — Trộn hai danh sách đã sắp xếp thành L3.
- `CountNode.cpp` — Đếm số lượng phần tử trong danh sách.
- `AddAfterQ.cpp` — Thêm phần tử mới sau phần tử K hoặc thêm cuối nếu K không tồn tại.

## Mục tiêu bài tập
- Làm quen với cấu trúc `Node` và phép thao tác trên danh sách liên kết đơn.
- Thực hiện các thao tác chèn, xóa, tìm kiếm, đảo ngược và sắp xếp.
- Biết cách đọc dữ liệu đầu vào, xử lý danh sách rồi in kết quả đúng định dạng.

## Hướng dẫn chạy
1. Mở file `.cpp` tương ứng với bài tập.
2. Biên dịch:
   - `g++ -std=c++17 <file>.cpp -o <file>.exe`
3. Chạy:
   - `<file>.exe`

## Gợi ý
- Với các bài xoá, hãy kiểm tra danh sách rỗng trước khi xóa.
- Với các bài sắp xếp, giữ nguyên thứ tự liên kết nếu không cần hoán đổi.
- Với các bài tìm kiếm, in `-1` khi không tìm thấy như yêu cầu.
