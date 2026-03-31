import sys


input = sys.stdin.readline
def main():
    # Leer el número de casos de prueba T [cite: 12, 40, 60]
    line = input().strip()
    if not line:
        return
    
    t = int(line)
    for caso in range(1, t + 1):
        str1 = input().lower().strip().replace(" ","")
        str2 = input().lower().strip().replace(" ","")
        
        ans = 'Yes'
        for i in str1:
            if str2.count(i)!= str1.count(i):
                ans = "No"
        print("Case " + str(caso) + ": "+ ans)
if __name__ == '__main__':
    sys.setrecursionlimit(200000)
    main()


'''
3
Tom Marvolo Riddle
I am Lord Voldemort
I am not Harry Potter
Hi Pretty Roar to man
Harry and Voldemort
Tom and Jerry and Harry
'''