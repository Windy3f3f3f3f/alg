def validate_stack_sequences(pushed, popped):
    stack = []
    pop_index = 0
    for num in pushed:
        stack.append(num)
        while stack and stack[-1] == popped[pop_index]:
            stack.pop()
            pop_index += 1
    return not stack

import sys
input = sys.stdin.read
data = input().split()
index = 0

q = int(data[index])
index += 1
results = []

for _ in range(q):
    n = int(data[index])
    index += 1
    pushed = list(map(int, data[index:index+n]))
    index += n
    popped = list(map(int, data[index:index+n]))
    index += n
    if validate_stack_sequences(pushed, popped):
        results.append("Yes")
    else:
        results.append("No")

for result in results:
    print(result)
