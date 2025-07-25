with open('input.txt', 'r', encoding = 'utf-8') as f:
  lines = f.readlines()
  k = int(lines[0])
  finalScores = []
  ind = -1
  for person in lines[1:]:
    scores = list(map(int, person.split()[-3:]))
    if min(scores) >= 40:
      finalScores.append(sum(scores))
  finalScores.sort()
  n = len(finalScores)
  if n <= k:
    print(0)
  elif finalScores.count(finalScores[-1]) > k:
    print(1)
  else:
    count_el = n - finalScores.index(finalScores[-k])
    ind = k
    while count_el > k:
      ind -= 1
      count_el = n - finalScores.index(finalScores[-ind])
    print(finalScores[-ind])