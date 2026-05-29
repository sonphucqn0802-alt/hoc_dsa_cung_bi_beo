# Insert Element

Hãy hoàn thành hàm Insert(HashTable &, STUDENT) để thêm một phần tử có kiểu dữ liệu STUDENT vào một bảng băm kiểu HashTable. Cho biết:

HashTable là loại bảng băm nối kết trực tiếp sử dụng danh sách liên kết đơn LIST để giải quyết đụng độ.
Hàm băm HashFunction sẽ biến đổi dữ liệu mã số sinh viên (MSSV) của học sinh thành chỉ số trong bảng băm bằng cách chia lấy dư MSSV cho kích thước tối đa của bảng băm.
Hệ số tải của bảng băm được cố định là 0.7, nghĩa là bảng băm luôn đảm bảo số phần tử được lưu trong bảng băm không chạm ngưỡng hoặc vượt quá 70% kích thước của bảng băm.
Số lượng phần tử cần thêm vào bảng băm không quá 1000 và bảng băm có kích thước không quá 1000 phần tử.
Input:
Dòng đầu tiên là kích thước tối đa M của bảng băm
Dòng thứ hai là số lượng sinh viên N được nhập thông tin để thêm vào bảng băm
5 * N dòng tiếp theo, mỗi 5 dòng thể hiện MSSV, Họ tên, Năm sinh, Giới tính, Điểm của sinh viên.
Output:
Bảng băm lưu trữ thông tin của các sinh viên
Lưu ý:
1) Chỉ cài đặt hàm Insert.
2) Các kiểu dữ liệu và các hàm cần thiết của các kiểu dữ liệu đã được cài đặt sẵn. Sinh viên có thể đọc để sử dụng.
3) Đầu vào và đầu ra đã được xử lý sẵn và phù hợp với định dạng nhập/xuất.

---

# Find Element

Hãy hoàn thành hàm Search(HashTable, MSSV) và các hàm cần thiết để tìm kiếm xem sinh viên với MSSV cần tìm có trong bảng băm không. Hàm Search sẽ trả về kết quả NULL nếu MSSV đó không tồn tại trong bảng băm. Ngược lại, trả về địa chỉ của MSSV đó trong bảng băm. Cho biết:

HashTable là loại bảng băm nối kết trực tiếp sử dụng danh sách liên kết đơn LIST để giải quyết đụng độ.
Hàm băm HashFunction sẽ biến đổi dữ liệu mã số sinh viên (MSSV) của học sinh thành chỉ số trong bảng băm bằng cách chia lấy dư MSSV cho kích thước tối đa của bảng băm.
Hệ số tải của bảng băm được cố định là 0.7, nghĩa là bảng băm luôn đảm bảo số phần tử được lưu trong bảng băm không chạm ngưỡng hoặc vượt quá 70% kích thước của bảng băm.
Số lượng phần tử cần thêm vào bảng băm không quá 1000 và bảng băm có kích thước không quá 1000 phần tử.

Input:
Dòng đầu tiên là kích thước tối đa M của bảng băm
Dòng thứ hai là số lượng sinh viên N được nhập thông tin để thêm vào bảng băm
5 * N dòng tiếp theo, mỗi 5 dòng thể hiện MSSV, Họ tên, Năm sinh, Giới tính, Điểm của sinh viên.
Số nguyên K thể hiện số lượng MSSV muốn tìm kiếm trong bảng băm
K dòng tiếp theo, mỗi dòng là MSSV cần tìm kiếm

Output:
K dòng, với mỗi dòng là:
Thông tin sinh viên nếu MSSV đó tồn tại trong bảng băm
Ngược lại, in ra "KHONG TIM THAY"