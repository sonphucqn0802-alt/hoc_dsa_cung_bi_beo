# Linear Search

Thuật toán tìm kiếm tuyến tính là một trong những thuật toán tìm kiếm đơn giản và dễ dàng cài đặt nhất. Ý tưởng của thuật toán là: với một mảng cho trước có N phần tử và phần tử cần tìm x, duyệt từ đầu mảng đến cuối mảng cho đến khi tìm được phần tử x.

Yêu cầu: Hãy cài đặt thuật toán tìm kiếm tuyến tính để tìm vị trí của x đầu tiên trong mảng có N phần tử và đếm số lần duyệt qua các phần tử.

Input:
Dòng đầu tiên là số nguyên N dương (0 < N < 10000)

Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng

Dòng cuối cùng là số nguyên x cần tìm

Output:
Dòng đầu tiên là vị trí của x đầu tiên trong mảng nếu tìm được. Nếu không tìm thấy thì xuất ra -1

Số lần duyệt qua các phần tử của mảng (từ đầu mảng đến cuối) để tìm được x

Dòng thứ ba là vị trí của x đầu tiên trong mảng (đếm từ cuối đến đầu) nếu tìm được. Nếu không tìm thấy thì xuất ra -1

Số lần duyệt qua các phần tử của mảng (từ cuối mảng đến đầu) để tìm được x

Nếu như ở 2 dòng đầu tiên mà không tìm thấy thì không cần xuất ra 2 dòng tiếp theo

---

# Binary Search

Thuật toán tìm kiếm nhị phân là một thuật toán tìm kiếm đơn giản nhưng có tốc độ tìm kiếm cực kỳ nhanh.

Ý tưởng của thuật toán là: với một mảng N phần tử đã được sắp xếp (tăng dần/hoặc giảm dần tùy theo người ra đề) và số nguyên x cần tìm, ta sẽ thực hiện tìm kiếm ở miền có khả năng xuất hiện x sau mỗi lần lặp.

Hãy cài đặt thuật toán tìm kiếm nhị phân để tìm vị trí của phần tử x trong mảng có N phần tử và đếm số lần duyệt qua các phần tử.

Input:
Dòng đầu tiên là số nguyên N dương (0 < N < 32000)

Dòng tiếp theo chứa N số nguyên Ai là các phần tử của mảng đã được sắp xếp tăng dần và không trùng nhau

Dòng cuối cùng là số nguyên x cần tìm

Output:
Dòng đầu tiên là vị trí của x được tìm thấy trong mảng. Nếu không tìm thấy thì xuất ra -1

Dòng tiếp theo là số lần duyệt qua các phần tử để tìm được x. Nếu không tìm thấy thì không cần xuất ra dòng này

---

Cho một dãy số nguyên a gồm N phần tử a1,a2,…,aN.

Có Q truy vấn, mỗi truy vấn cho một số nguyên x. Bạn hãy trả lời xem số nguyên x này có trong dãy a hay không?

Lưu ý: Trong template đã đảm bảo mảng ban đầu sau khi nhập vào sẽ được sắp xếp, các bạn chỉ cần hoàn thành hàm myBinarySearch.

Input:
 - Dòng đầu tiên là 2 số nguyên dương N, Q (1≤N,Q≤105)
 - Dòng tiếp theo chứa N số nguyên ai(−109≤ai≤109)
 là các phần tử của mảng.

- Q dòng tiếp theo, mỗi dòng chứa một số x là câu hỏi của truy vấn.

Output:
Gồm Q dòng, mỗi dòng gồm một câu trả lời. Nếu x trong dãy a thì in ra ‘YES'. Ngược lại, in ra ‘NO'.

---

# Binary Search on Strings

Thuật toán tìm kiếm nhị phân là một thuật toán tìm kiếm đơn giản nhưng có tốc độ tìm kiếm cực kỳ nhanh. Tuy nhiên, đa phần các hướng dẫn và khóa học trên mạng đều hướng dẫn người học cài đặt trên mảng số nguyên trong khi trong thực tế chỉ cần mảng có thể sắp xếp được thì ra có thể áp dụng thuật toán tìm kiếm nhị phân.

Hãy cài đặt thuật toán tìm kiếm nhị phân trên mảng chuỗi có N phần tử.

Input:
Dòng đầu tiên là số nguyên N dương (0 < N < 2000)

N dòng tiếp theo chứa các phần tử Ai trong mảng, mỗi phần tử là một chuỗi với độ dài không quá 10. Các phần tử này đã được sắp xếp theo thứ tự bảng chữ cái

Dòng cuối cùng là chuỗi x cần tìm

Output:
Dòng đầu tiên là vị trí của x được tìm thấy trong mảng. Nếu không tìm thấy thì xuất ra -1

Dòng tiếp theo là số lần duyệt qua các phần tử để tìm được x. Nếu không tìm thấy thì không cần xuất ra dòng này