def count_errors (dictionary, text):
    new_dict = {}
    for word in dictionary:
        lowered_word = word.lower()
        if lowered_word not in new_dict:
            new_dict[lowered_word] = set()
        new_dict[lowered_word].add(word)


    def countt(word):
        return sum(1 for char in word if char.isupper())


    errors_count = 0

    words = text.split()
    for word in words:
        lowered_word = word.lower()

        if lowered_word in new_dict:
            if word not in new_dict[lowered_word]:
                errors_count += 1
        else:
            if countt(word) != 1:
                errors_count += 1

    return errors_count

n = int(input())
dictionary = [input().strip() for i in range(n)]
text = input().strip()
errors = count_errors(dictionary, text)
print(errors)