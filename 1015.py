while True:
    try:
        n, m, g = map(int, input().split())
    except ValueError:
        break
    
    scores = list(map(int, input().split()))
    
    count = 0
    output_dic = {}
    for student in range(n):
        result = list(input().split())
        
        total = 0
        
        if int(result[1]) == 0:
            continue
        
        for score in result[-int(result[1]):]:
            total += scores[int(score) - 1]
            
        if total >= g:
            count += 1
            output_dic[result[0]] = total
                
    print(count)
    
    for key, value in sorted(output_dic.items(), key=lambda x: (-x[1], x[0])):
        print(key, value)