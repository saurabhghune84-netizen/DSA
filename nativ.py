
def naive_search(text, pattern):
    n = len(text)
    m = len(pattern)
    found = False

    for i in range(n - m + 1):
        if text[i:i+m] == pattern:
            print("Pattern found at index:", i)
            found = True

    if not found:
        print("Pattern not found")


text = input("Enter text: ")
pattern = input("Enter pattern: ")

naive_search(text, pattern)
