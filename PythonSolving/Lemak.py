from math import fabs
 
 
def Lemak(sy):
    sy_ord = (ord(sy) - 96)
    if sy_ord < 14:
        return 'z', (ord('z') - 96) - sy_ord
    else:
        return 'a', sy_ord - (ord('a') - 96)
 
 
n, k = map(int, input().split())
word = input()
res = ''
i = 0
while i < n:
    n_s = ''
    m_d = Lemak(word[i])
    if m_d[1] > k and m_d[0] == 'a':
        n_s = chr(int(ord(word[i]) - k))
    elif m_d[1] > k and m_d[0] == 'z':
        n_s = chr(int(ord(word[i]) + k))
    else:
        n_s = m_d[0]
    res += n_s
    k -= fabs(ord(word[i]) - ord(n_s))
    i += 1
print(res if k == 0 else -1)