# Thuật toán tìm kiếm

Thư mục này chứa các bài tập minh hoạ cho thuật toán tìm kiếm cơ bản trong C++.

## Nội dung chính
- `LinearSearch.cpp` — Tìm kiếm tuyến tính trong mảng số nguyên; in vị trí phần tử đầu tiên tìm được và số lần duyệt qua mảng.
- `BinarySearch.cpp` — Cho một dãy số nguyên a gồm N phần tử a1, a2, …, aN.
  Có Q truy vấn, mỗi truy vấn cho một số nguyên x. Bạn hãy trả lời xem số nguyên x này có trong dãy a hay không?
  Lưu ý: Trong template đã đảm bảo mảng ban đầu sau khi nhập vào sẽ được sắp xếp, các bạn chỉ cần hoàn thành hàm myBinarySearch.
  Input:
   - Dòng đầu tiên là 2 số nguyên dương N, Q (1 ≤ N, Q ≤ 10^5)
   - Dòng tiếp theo chứa N số nguyên ai (−10^9 ≤ ai ≤ 10^9) là các phần tử của mảng.
   - Q dòng tiếp theo, mỗi dòng chứa một số x là câu hỏi của truy vấn.
  Output:
  Gồm Q dòng, mỗi dòng gồm một câu trả lời. Nếu x trong dãy a thì in ra ‘YES'. Ngược lại, in ra ‘NO'.
- `BinarySearch'.cpp` — Tìm kiếm nhị phân với nhiều truy vấn trên mảng đã sắp xếp; với mỗi giá trị truy vấn in `YES` nếu tồn tại, `NO` nếu không.
- `BinarySearch''.cpp` — Tìm kiếm nhị phân trên mảng chuỗi đã sắp xếp; kiểm tra xem chuỗi cần tìm có trong dữ liệu đầu vào hay không.
- `Search_3D_point.cpp` — Tìm kiếm một điểm trong không gian 3D theo toạ độ; xác định điểm có nằm trong khoảng điểm mô tả không?
- `Find_MEX` — Tìm kiếm MEX (Minimum Excluded Value) trong mảng số nguyên; xác định giá trị nhỏ nhất không xuất hiện trong mảng.

## Mô tả chung
- Các bài tập này tập trung vào cách vận hành của tìm kiếm tuyến tính và tìm kiếm nhị phân.
- Chú ý: với tìm kiếm nhị phân, dữ liệu đầu vào phải được sắp xếp đúng yêu cầu trước khi tìm.

## Cách chạy
1. Mở file `.cpp` cần chạy.
2. Biên dịch với g++:
   - `g++ -std=c++17 <file>.cpp -o <file>.exe`
3. Chạy file thực thi:
   - `<file>.exe`

