def maximize_value(X, Y, n, pieces):
    table = [[0] * (Y + 1) for _ in range(X + 1)]

    for i in range(1, X + 1):
        for j in range(1, Y + 1):
            table[i][j] = max(table[i - 1][j], table[i][j - 1])

            for k in range(n):
                ai, bi, pi = pieces[k]
                if i >= ai and j >= bi:
                    table[i][j] = max(table[i][j], max(table[i][j - bi] + pi, table[i - ai][j] + pi))
                if i >= bi and j >= ai:
                    table[i][j] = max(table[i][j], table[i - bi][j - ai] + pi)

    return table[X][Y]

def main():
    X, Y = map(int, input().split())
    n = int(input())

    pieces = [list(map(int, input().split())) for _ in range(n)]

    result = maximize_value(X, Y, n, pieces)
    print(result)

if __name__ == "__main__":
    main()
