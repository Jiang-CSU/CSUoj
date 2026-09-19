def recursion(my_list, new_list):
    if not my_list:
        print(*new_list, sep=" ")
        return

    for i in range(len(my_list) - 1, -1, -1):
        x = my_list.pop(i)
        new_list.append(x)

        recursion(my_list, new_list)

        new_list.pop()
        my_list.insert(i, x)
    
while True:
    try:
        n = int(input())
    except EOFError:
        break
    
    my_list = [i for i in range(1, n + 1)]
    new_list = []
    recursion(my_list, new_list)
    
    