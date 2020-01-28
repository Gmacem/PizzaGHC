
inp = input().split()

order_num = int(inp[0])
pizza_types_num = int(inp[1])

types = []

for i, num in enumerate(input().split()):
    types.append((i, int(num), int(num)))


def knapsack01_dp(items, limit):
    table = [[0 for __ in range(limit + 1)] for _ in range(len(items) + 1)]

    for j in range(1, len(items) + 1):
        item, wt, val = items[j-1]
        for w in range(1, limit + 1):
            if wt > w:
                table[j][w] = table[j-1][w]
            else:
                table[j][w] = max(table[j-1][w],
                                  table[j-1][w-wt] + val)

    result = []
    w = limit
    for j in range(len(items), 0, -1):
        was_added = table[j][w] != table[j-1][w]

        if was_added:
            item, wt, val = items[j-1]
            result.append(items[j-1])
            w -= wt

    return result


result = knapsack01_dp(types, order_num)

print(len(result))

for _ in reversed(result):
    print(_[0], end=' ')

