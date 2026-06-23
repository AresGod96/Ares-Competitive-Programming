## Problem VNOJ VOSSEVEN - Bài toán số 7 <img src="../../boj-icon/bronze1.svg" alt="Bronze 1" width="20" height="20">
Nguồn: [VNOI Online Judge](https://oj.vnoi.info/problem/vosseven)

## [Đề bài](https://oj.vnoi.info/problem/vosseven)

## Độ khó <img src="../../boj-icon/bronze1.svg" alt="Bronze 1" width="20" height="20">

## Thẻ
- tổng tiền tố (prefix sum)
- xâu ký tự

## Lời giải

Cho một xâu $s$ gồm $N$ chữ số (với $N \le 10^6$), với mỗi độ dài $i \ge 1$ ta cần đếm xem có bao nhiêu xâu con gồm **đúng $i$ chữ số `7` liên tiếp** xuất hiện trong $s$ — chỉ in ra những độ dài có số lần xuất hiện khác $0$, theo thứ tự tăng dần.

### Quy về các đoạn (run)

Một xâu con gồm $i$ chữ số `7` liên tiếp chỉ có thể nằm bên trong một *đoạn `7` cực đại* (maximal run). Nếu một đoạn cực đại có độ dài $L$, thì số cửa sổ độ dài $i$ vừa khít bên trong nó là

$$\max(0,\ L - i + 1).$$

Vậy đáp số cho một độ dài $i$ cố định là

$$\text{ans}[i] = \sum_{\text{các đoạn}} \max(0,\ L - i + 1).$$

Vòng lặp đôi trực tiếp theo (độ dài $i$) × (các đoạn) có độ phức tạp $O(N^2)$ trong trường hợp xấu nhất (ví dụ một đoạn duy nhất gồm một triệu chữ `7`), quá chậm. Ta cần cộng dồn đóng góp của tất cả các đoạn trong thời gian tuyến tính.

### Kỹ thuật mảng hiệu

Duyệt xâu một lần, duy trì `cnt` = độ dài đoạn `7` hiện tại kết thúc tại vị trí đang xét (đặt lại về $0$ khi gặp ký tự khác `7`). Khi đang ở một vị trí có số đếm chạy là `cnt`, vị trí đó là **điểm kết thúc bên phải** của đúng một cửa sổ với mỗi độ dài $1, 2, \dots, \text{cnt}$. Nói cách khác, riêng ký tự này đóng góp $+1$ vào $\text{ans}[1], \text{ans}[2], \dots, \text{ans}[\text{cnt}]$.

Cộng $+1$ vào cả đoạn $[1, \text{cnt}]$ cho từng ký tự một cách ngây thơ lại tốn $O(N^2)$, nên ta dùng **mảng hiệu** $f$:

$$f[1] \mathrel{+}= 1, \qquad f[\text{cnt}+1] \mathrel{-}= 1.$$

Sau khi duyệt xong, một lần lấy tổng tiền tố biến $f$ thành đáp số:

$$f[i] \mathrel{+}= f[i-1].$$

Lúc này $f[i]$ bằng số vị trí có số đếm chạy $\ge i$, đúng bằng số cửa sổ `7` độ dài $i$ — tức là $\text{ans}[i]$.

Điều này đúng vì, cộng dồn trên một đoạn độ dài $L$, các số đếm chạy nhận lần lượt các giá trị $1, 2, \dots, L$, và số vị trí có số đếm $\ge i$ là $L - i + 1$, tái tạo lại đúng công thức ở trên. Ký tự khác `7` đặt `cnt = 0`, nên đóng góp `f[1] += 1, f[1] -= 1`, không làm gì cả — gọn và không cần rẽ nhánh.

### Vì sao đúng với ví dụ

Với `72774777` các đoạn cực đại là `7`, `77`, `777` (độ dài $1, 2, 3$):
- độ dài $1$: $1 + 2 + 3 = 6$
- độ dài $2$: $0 + 1 + 2 = 3$
- độ dài $3$: $0 + 0 + 1 = 1$

cho ra kết quả mong đợi
```
1 6
2 3
3 1
```

### Lưu ý cài đặt

- `len` lưu đoạn dài nhất từng gặp, nên vòng lặp cuối chỉ in các độ dài $1 \dots \text{len}$ — tự động bỏ qua các độ dài có số lần xuất hiện bằng $0$ vượt quá đoạn dài nhất. (Các độ dài bên trong luôn có số đếm dương, vì bất kỳ độ dài $i \le \text{len}$ nào cũng vừa khít trong đoạn dài nhất.)
- Số lần xuất hiện có thể lớn tới $\approx N^2/2 \approx 5 \cdot 10^{11}$ với một đoạn khổng lồ duy nhất, nên mảng tích lũy `f[]` phải là **64-bit** (`long long`); kiểu 32-bit sẽ bị tràn.
- `f` có kích thước `MAXN = 1e6 + 100`, và `cnt + 1` lớn nhất là `len + 1 ≤ N + 1`, nên phép ghi `--f[cnt + 1]` không vượt biên.
- Đề bảo đảm có ít nhất một chữ `7`, nên `len ≥ 1` và luôn có dữ liệu xuất ra.

### Độ phức tạp
- Duyệt + cập nhật đoạn: $O(N)$
- Tổng tiền tố + xuất kết quả: $O(\text{len}) \le O(N)$
- **Tổng cộng**: thời gian $O(N)$, bộ nhớ $O(N)$
