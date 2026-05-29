# Bài tập bảng băm

Thư mục này chứa các bài tập thực hành về bảng băm (hash table) với dữ liệu sinh viên.

## Nội dung chính
- `Insert_Element.cpp` — Cài đặt hàm `Insert(HashTable &, STUDENT)` để thêm sinh viên vào bảng băm.
- `Find_Element.cpp` — Cài đặt hàm `Search(HashTable, MSSV)` để tìm sinh viên theo MSSV.

## Mô tả chung
- Bảng băm sử dụng giải pháp chaining với danh sách liên kết đơn để xử lý đụng độ.
- Hàm băm chuyển MSSV sang chỉ số bảng băm bằng `MSSV % kích thước_hash_table`.
- Hệ số tải cố định là 0.7.

## Hướng dẫn chạy
1. Mở file `.cpp` cần chạy.
2. Biên dịch:
   - `g++ -std=c++17 <file>.cpp -o <file>.exe`
3. Chạy:
   - `<file>.exe`

## Lưu ý
- Chỉ hoàn thành hàm được yêu cầu, các phần còn lại đã có sẵn trong template.
- Đảm bảo định dạng đầu vào/đầu ra giống đề bài để không bị sai kết quả.
