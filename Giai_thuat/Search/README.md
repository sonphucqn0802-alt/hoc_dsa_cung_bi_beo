# Thuật toán tìm kiếm

Thư mục này chứa các bài tập minh họa về thuật toán tìm kiếm trong C++. Các ví dụ ở đây giúp bạn làm quen với hai hướng tiếp cận chính: tìm kiếm tuyến tính và tìm kiếm nhị phân, đồng thời thấy cách áp dụng chúng vào các bài toán thực tế.

## Nội dung chính

### 1. Tìm kiếm tuyến tính
- LinearSearch.cpp — tìm vị trí đầu tiên của một phần tử x trong mảng, trả về -1 nếu không tìm thấy.
- LinearSearch'.cpp — tìm cả vị trí đầu tiên và vị trí cuối cùng của x, đồng thời đếm số bước duyệt.
- LinearSearch'''.cpp — bài toán phân chia mảng thành hai dãy con để tối đa hóa tổng trọng số, giúp rèn tư duy so sánh và lựa chọn giá trị.

### 2. Tìm kiếm nhị phân
- BinarySearch.cpp — kiểm tra xem x có tồn tại trong mảng đã sắp xếp hay không với nhiều truy vấn.
- BinarySearch'.cpp — tìm vị trí của x trong mảng đã sắp xếp và đếm số lần duyệt.
- BinarySearch''.cpp — áp dụng tìm kiếm nhị phân trên mảng chuỗi đã sắp xếp theo thứ tự bảng chữ cái.

### 3. Các bài toán vận dụng
- Search_3D_point.cpp — tìm các điểm trong không gian 3 chiều có khoảng cách từ gốc tọa độ thuộc đoạn [b, e].
- Find_MEX.cpp — tìm giá trị MEX (Minimum Excluded Value) đầu tiên của mảng.
- Find_MEX'.cpp — tính MEX cho từng prefix của mảng.
- PiNetwork.cpp — tìm mức giá tối thiểu để cân bằng cung và cầu bằng cách dùng binary search.
- Renew.cpp — xác định số ngày cần thiết để chặt hết cây, là một bài toán tối ưu hóa áp dụng tìm kiếm nhị phân.

## Mục tiêu học tập
- Hiểu cách hoạt động của tìm kiếm tuyến tính và tìm kiếm nhị phân.
- Nhận biết khi nào nên dùng từng phương pháp.
- Thấy cách biến một bài toán thành bài toán “tìm giá trị thỏa mãn điều kiện” để áp dụng binary search.

## Mẹo khi học
- Tìm kiếm tuyến tính phù hợp với dữ liệu chưa sắp xếp hoặc kích thước nhỏ.
- Tìm kiếm nhị phân chỉ hiệu quả khi dữ liệu đã được sắp xếp.
- Với các bài toán cần tìm giá trị nhỏ nhất/lớn nhất thỏa mãn điều kiện, hãy nghĩ tới binary search.

## Cách chạy
1. Mở file .cpp cần chạy trong thư mục này.
2. Biên dịch bằng g++:
   - g++ -std=c++17 <file>.cpp -o <file>.exe
3. Chạy file thực thi:
   - <file>.exe

