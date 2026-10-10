// class Solution {
// public:
//     int fib(int n) {
//     int first = 0, second = 1, nextTerm;
//     if()
//     for (int i = 0; i < n; i++) {
//         if (i <= 1) {
//             nextTerm = i;
//         } else {
//             nextTerm = first + second;
//             first = second;
//             second = nextTerm;
//         }
//     }
//         return first+second;
//     }
// };
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
class Solution {
public:
    int fib(int n)
    {
        return fibonacci(n);
    }
};