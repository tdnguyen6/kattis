def is_power_of_two(n):
  return (n != 0) and (n & (n-1) == 0)

def getTerms(sum, num):
  terms = []
  mid = sum // num
  distance = -num // 2 + 1
  for _ in range (num):
    terms.append(mid + distance)
    distance += 1
  return terms

def getCorrectTerms(inputSum):
  i = 2
  curSum = -1
  terms = []
  while curSum != inputSum:
    terms = getTerms(inputSum, i)
    curSum = sum(terms)
    i += 1
  return terms

def customPrint(n, terms):
  print(n, end=" = ")
  size = len(terms)
  for i in range(size):
    print(terms[i], end="")
    if i < size - 1:
      print(" + ", end="")
  print()

def consecutivesums():
  T = int(input())
  for _ in range(T):
    n = int(input())
    if is_power_of_two(n):
      print("IMPOSSIBLE")
    else:
      correctTerms = getCorrectTerms(n)
      customPrint(n, correctTerms)

consecutivesums()