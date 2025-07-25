import sys
input = sys.stdin.read

data = input().splitlines()

accounts = {}

def deposit(name, amount):
 if name not in accounts:
  accounts[name] = 0
 accounts[name] += amount

def withdraw(name, amount):
 if name not in accounts:
  accounts[name] = 0
 accounts[name] -= amount

def balance(name):
 if name in accounts:
  print(accounts[name])

 else:
  print("ERROR")

def income(p):
 for name, balance in accounts.items():
  if balance > 0:
   accounts[name] += (balance*p)//100

def transfer(name1, name2, amount):
 if name1 not in accounts:
  accounts[name1] = 0
 if name2 not in accounts:
  accounts[name2] = 0
 accounts[name1] -= amount
 accounts[name2] += amount

for line in data:
 parts = line.split()
 command = parts[0]
 if command == "DEPOSIT":
  name, amount = parts[1], int(parts[2])
  deposit(name, amount)

 elif command == "WITHDRAW":
  name, amount = parts[1], int(parts[2])
  withdraw(name, amount)
 
 elif command == "BALANCE":
  name = parts[1]
  balance(name)

 elif command == "INCOME":
  p = int(parts[1])
  income(p)
 elif command == "TRANSFER":
  name1, name2, amount = parts[1], parts[2], int(parts[3])
  transfer(name1, name2, amount)