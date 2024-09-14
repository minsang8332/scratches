/**
 * 2024.05.25
 * @author minsa
 * 방송대 알고리즘 탐색에 대하여 자바스크립트로 작성해보았음
 */

const sequential = (arr = [], x) => {
    let i = 0
    while (i < n && arr[i] != x) {
        i = i + 1
    }
    return i
}
console.log(
    '순차 탐색',
    sequential([], 4)
)
