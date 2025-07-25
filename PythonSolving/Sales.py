purchases = {}

with open('input.txt', 'r') as f:
  for line in f:
    name, item, count = line.split()
    count = int(count)
    if name not in purchases:
      purchases[name] = {}
    if item not in purchases[name]:
      purchases[name][item] = 0
    purchases[name][item] += count
buyer = sorted(purchases.keys())

for names in buyer:
  print(names + ":")
  products = sorted(purchases[names].keys())
  for item in products:
    print(item, purchases[names][item])