# Cây nhị phân (Tree)

Thư mục này chứa các bài tập về cây nhị phân và thao tác trên cây trong C++.

## Đề mục bài tập
- `Count_Node_In_Tree.cpp` — Đếm tổng số nút trong cây.
- `Count_Node_With_One_Child.cpp` — Đếm số nút có đúng một con.
- `Count_Node_With_Two_Child.cpp` — Đếm số nút có hai con.
- `Count_Even_Node.cpp` — Đếm số nút có giá trị chẵn.
- `Count_Leaf_Node.cpp` — Đếm số nút lá trong cây.
- `Count_Height_Of_Tree.cpp` — Đếm chiều cao của cây.
- `Delete_Node.cpp` — Xóa nút có giá trị cụ thể trong cây.
- `Brother_Relationship.cpp` — Kiểm tra quan hệ anh em giữa hai nút.
- `Dad_Son_Relationships.cpp` — Kiểm tra quan hệ cha-con giữa hai nút.
- `Make_Binary_Tree.cpp` — Xây dựng cây và duyệt theo nhiều thứ tự.
- `Find_MaxMin.cpp` — Tìm giá trị lớn nhất và nhỏ nhất trong cây.

## Mục tiêu bài tập
- Luyện tập xây dựng cây nhị phân theo dữ liệu nhập.
- Áp dụng các phép duyệt cây và kiểm tra cấu trúc cây.
- Xây dựng hàm đếm, tìm kiếm và kiểm tra mối quan hệ giữa các nút.

## Hướng dẫn chạy
1. Biên dịch file `.cpp` cần chạy:
   - `g++ -std=c++17 <file>.cpp -o <file>.exe`
2. Chạy chương trình:
   - `<file>.exe`

## Lưu ý
- Các bài tập thường mô tả cây được xây dựng từ một dãy số bằng cách thêm từng phần tử vào cây.
- Kiểm tra kỹ yêu cầu xuất ra trước khi hoàn thành, đặc biệt với các bài liên quan đến quan hệ anh em/cha con.


# Count Leaf Node

Nhận vào một dãy gồm N số nguyên, hãy hình thành cây NPTK bằng cách thêm các số này một cách tuyến tính và viết hàm đếm tổng số lượng nút lá trong cây 