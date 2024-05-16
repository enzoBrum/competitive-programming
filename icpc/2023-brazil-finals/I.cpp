s = input()
n = int(input())

inversions = 0
freq = [0 for _ in range(26)]

for c in s:
	for i in range(ord(c) - ord('a') +1 , len(freq)):
		inversions += freq[i]
	freq[ord(c) - ord('a')] += 1
	
prefix = freq[:]
for i in range(1,len(freq)):
	prefix[i] += prefix[i-1]

inversions *= n
aux = n * n - n * (n + 1) // 2

for i in range(1, 26):
	if freq[i]:
		inversions += freq[i]*aux*prefix[i-1]
		
print(inversions % (int(1e9) + 7))
